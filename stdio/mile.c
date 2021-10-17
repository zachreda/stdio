//
//  mile.c
//  stdio
//
//  Created by Zach Reda on 10/16/21.
//

#include "mile.h"


const int BUFSIZE = 1000;


mile* mopen(char *name, char *mode){
    mile *filep = malloc(sizeof *filep);
    
    
    if (mode=='r') {
        filep->_df = open(name, O_RDONLY); //open file for reading
    }
    if (mode=='w') {
        filep->_df = open(name, O_WRONLY); //open file for writing
    }
    
    if (filep->_df != -1) {
        filep->_buf = (char *)malloc(BUFSIZE*sizeof(char)); //allocate space for the buffer
        filep->_mode = mode;
    }
    
    return filep;
}

int mread(void *b, int len, mile *m){
    if (m->_mode!='r') {
        return -1; //file must be open for reading if you want to call mread
    }
    int numr = read(m->_df, b, len);
    return numr;
}

int mclose(mile *m){
    if (sizeof(m->_mode)!=0) {
        free(m->_buf);
        free(m);
        return 0;
    }
    
    return -1; //if there is no mode set then the file then the file is already closed
}
