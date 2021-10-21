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
            if (x==-1) {
                return -1;
            }
            m->_rbuf->_r++; //increment current read position
            return *b;
        }
        
    }
    return -1;
}

int mungetc(int c, mile *m){
    if (m->_rbuf->_buf!=NULL && m->_df!=-1) { //check to see if file has read permission and that there is data in the buffer
        if (m->_rbuf->_r <= m->_rbuf->_re) { //if the current position is less than or equal to the last mem loc holding data
            if (m->_rbuf->_r==0) {
                return -1;
            }
            if (m->_rbuf->_buf+m->_rbuf->_r == c) {
                m->_rbuf->_r--;
            }
            
        }
    }
    return -1;
        
}

int mread_int(mile *m){
    int sizeofint = 4;
    void *tmp = malloc(sizeofint*sizeof(int));
    
    off_t count = 0;
    if (m->_rbuf->_buf!=NULL && m->_df!=-1) {
        while (m->_rbuf->_r <= m->_rbuf->_re && count < sizeofint) {
            int f = mgetc(m);
            memcpy(tmp+count,&f, 1);
            count++;
        }
        int s = atoi(tmp);
        free(tmp);
        return s; //success
    }
    
    free(tmp);
    return -1;
}
