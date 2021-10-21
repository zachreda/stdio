//
//  mile.c
//  stdio
//
//  Created by Zach Reda on 10/16/21.
//

#include "mile.h"


const int RBUFSIZE = 100;
const int WBUFSIZE = 100;

mile* mopen(char *name, char *mode){
    mile *filep = malloc(sizeof *filep);
    filep->_rbuf = malloc(sizeof(readbuff));
    filep->_wbuf = malloc(sizeof(writebuff));
    
    
    if (strcmp(mode,"r")==0) {
        filep->_df = open(name, O_RDONLY | O_CREAT); //open file for reading
        if (filep->_df != -1) {
            filep->_rbuf->_buf = (char *)malloc(RBUFSIZE*sizeof(char)); //allocate space for the buffer
            filep->_rbuf->_r=0;
            filep->_rbuf->_re=0;
            filep->_rbuf->size=RBUFSIZE;
        }
        filep->_mode=*mode;
        filep->_wbuf = NULL;
    }
    
    else if (strcmp(mode,"w")==0) {
        filep->_df = open(name, O_WRONLY | O_CREAT | O_TRUNC ); //open file for writing
        if (filep->_df != -1) {
            filep->_wbuf->_buf = (char *)malloc(WBUFSIZE*sizeof(char)); //allocate space for the buffer
            filep->_wbuf->_w=0;
            filep->_wbuf->size=WBUFSIZE;
        }
        filep->_mode=*mode;
        filep->_rbuf = NULL;
    }
    else if (strcmp(mode,"a")==0) {
        filep->_df = open(name, O_WRONLY | O_CREAT | O_APPEND ); //open file for appending
        if (filep->_df != -1) {
            filep->_wbuf->_buf = (char *)malloc(WBUFSIZE*sizeof(char)); //allocate space for the buffer
            filep->_wbuf->_w = 0;
            filep->_wbuf->size=WBUFSIZE;
        }
        filep->_mode=*mode;
        filep->_rbuf = NULL;
    }
    else  {
        free(filep->_rbuf);
        free(filep->_wbuf);
        free(filep);
        return NULL;
    }
    
    
    
    return filep;
}

void freeReadBuffer(mile *m){
    free(m->_rbuf->_buf);
    m->_rbuf->_buf = (char *)malloc(RBUFSIZE*sizeof(char)); //allocate space for the buffer
    m->_rbuf->_r=0;
    m->_rbuf->_re=0;
    m->_rbuf->size=RBUFSIZE;
}

int mread(void *b, int len, mile *m){
    off_t numr =0;
    off_t res =0; // to track if end of file
    if (m->_mode!='r') {
        return -1; //file must be open for reading if you want to call mread
    }
    
    for (int i=0; i<len; i++) {
        if (m->_rbuf->_re == RBUFSIZE) {
            freeReadBuffer(m);
        }
        res= read(m->_df, (void*)m->_rbuf->_buf+m->_rbuf->_re, 1);
        if (res != 0) {
            memcpy(b+i, m->_rbuf->_buf+m->_rbuf->_re, 1);
            m->_rbuf->_re += 1;
            numr+=res;
        }
    }
 
    return numr;
}

int flush(mile *m){
    off_t numf = write(m->_df, m->_wbuf->_buf, m->_wbuf->_w);
    free(m->_wbuf->_buf);
    m->_wbuf->_buf = (char *)malloc(WBUFSIZE*sizeof(char)); //allocate space for the buffer
    m->_wbuf->_w=0;
    m->_wbuf->size=WBUFSIZE;
    return numf;
}

int mwrite(void *b, int len, mile *m){
    off_t numw =0;
    if (m->_mode=='w' | m->_mode=='a') {
        for (int i=0; i<len; i++) {
            if (m->_wbuf->_w == WBUFSIZE) {
                int res = flush(m);
                i--;
                if (res==-1)
                    return -1;
                numw+=res;
            }
            else{
                memcpy(m->_wbuf->_buf+m->_wbuf->_w, b+i, 1);
                m->_wbuf->_w++;
            }
            
        }
    }
    else
        return -1; //file must be open for writing or appending if you want to call mwrite
    
    
    
    numw+=flush(m);
    
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


