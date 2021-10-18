//
//  mile.c
//  stdio
//
//  Created by Zach Reda on 10/16/21.
//

#include "mile.h"


const int RBUFSIZE = 1000;
const int WBUFSIZE = 10;


mile* mopen(char *name, char *mode){
    mile *filep = malloc(sizeof *filep);
    filep->_rbuf = malloc(sizeof(readbuff));
    filep->_wbuf = malloc(sizeof(writebuff));
    
    
    if (strcmp(&mode,"r")==0) {
        filep->_df = open(name, O_RDONLY); //open file for reading
        if (filep->_df != -1) {
            filep->_rbuf->_buf = (char *)malloc(RBUFSIZE*sizeof(char)); //allocate space for the buffer
            filep->_rbuf->_r=0;
            filep->_rbuf->_re=0;
            filep->_rbuf->size=RBUFSIZE;
        }
        filep->_mode=mode;
        filep->_wbuf = NULL;
    }
    
    else if (strcmp(&mode,"w")==0) {
        filep->_df = open(name, O_WRONLY); //open file for reading
        if (filep->_df != -1) {
            filep->_wbuf->_buf = (char *)malloc(WBUFSIZE*sizeof(char)); //allocate space for the buffer
            filep->_wbuf->_w=0;
            filep->_wbuf->size=WBUFSIZE;
        }
        filep->_mode=mode;
        filep->_rbuf = NULL;
    }
    
    
    return filep;
}

int mread(void *b, int len, mile *m){
    int numr;
    if (m->_mode!='r') {
        return -1; //file must be open for reading if you want to call mread
    }
    
    if (m->_rbuf->_re == 0) { //if the current position is 0, meaning no files have been read yet. //MUST ADD INCREMENT
        numr = read(m->_df, (void*)m->_rbuf->_buf, len);
        m->_rbuf->_re = numr - 1; //index starts at 0
        memcpy(b, m->_rbuf->_buf, len);
    }
    else{
        memcpy(b, m->_rbuf->_buf, len);
        numr = len;
    }
 
    return numr;
}

int flush(mile *m){
    int numf = write(m->_df, m->_wbuf->_buf, m->_wbuf->size);
    free(m->_wbuf->_buf);
    m->_wbuf->_buf = (char *)malloc(WBUFSIZE*sizeof(char));
    m->_wbuf->_w=0;
    return numf;
}

int mwrite(void *b, int len, mile *m){
    int numw;
    if (m->_mode!='w') {
        return -1; //file must be open for writing if you want to call mwrite
    }
    m->_wbuf->size=len;
    
    memcpy(m->_wbuf->_buf, b, len);
    flush(m);
    
    return numw;
}

int mclose(mile *m){
    //must add in close method
    if (sizeof(m->_mode)!=0) {
        free(m->_rbuf);
        free(m);
        return 0;
    }
    
    return -1; //if there is no mode set then the file then the file is already closed
}
