//
//  smile.c
//  stdio
//
//  Created by Zach Reda on 10/18/21.
//

#include "smile.h"

int mgetc(mile *m){
   //check to see if file has read permission and that there is data in the buffer
    if (m->_rbuf->_buf!=NULL && m->_df!=-1) {
        
        if (m->_rbuf->_r <= m->_rbuf->_re) {
            int *b= (int *)malloc(sizeof(int)); //contains the data to be returned
            int x = mread(b, 1, m); // x holds how much data is returned.
            return *b;
        }
        
    }
    return -1;
}

int mungetc(int c, mile *m){
    if (m->_rbuf->_buf!=NULL && m->_df!=-1) {
        if (m->_rbuf->_r <= m->_rbuf->_re) {
            memcpy(m->_rbuf->_buf+m->_rbuf->_r, &c, 1);
        }
    }
    return -1;
        
}

int mread_int(int *i, mile *m){
    int sizeofint = 4;
    void *tmp = (int *)malloc(sizeofint*sizeof(int));
    off_t count = 0;
    if (m->_rbuf->_buf!=NULL && m->_df!=-1) {
        while (m->_rbuf->_r <= m->_rbuf->_re && count < sizeofint) {
            int f = mgetc(m);
            memcpy(tmp+count,&f, 1);
            count++;
        }
        memcpy(i, tmp, count);
        return 0; //success
    }
    
    return -1;
}
