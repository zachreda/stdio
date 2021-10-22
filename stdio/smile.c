//
//  smile.c
//  stdio
//
//  Created by Zach Reda on 10/18/21.
//

#include "smile.h"

int mgetc(MILE *m){
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

int mungetc(int c, MILE *m){
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

int mread_int(MILE *m){
    int sizeofint = sizeof(int);
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

int split(int *x, int factor){
    int ret = *x/factor;
    *x = *x%factor;
    return ret;
}

int countDigits(int n){
    int count =0;
    do {
        n /= 10;
        ++count;
      } while (n != 0);
    return count;
}

int mwrite_int(int i, MILE *m){
    int size = countDigits(i);
    off_t count = 0;
    int factor = 1000;
    switch (size) {
        case 3:
            factor/=10;
            break;
        case 2:
            factor/=100;
            break;
        case 1:
            factor/=1000;
        default:
            break;
    }
    
    
    if (i<0) {
        mwrite("-", 1, m);
        i*=-1;
        count++;
    }
    
    for (int j=0; j<size; j++) {
        int tmp = split(&i, factor);
        if (tmp==0 && j==0) {
            break;
        }
        else {
            mputc(tmp, m);
        }
        factor/=10;
        count++;
    }

    
    return count;
}

int mputc(int i, MILE *m){
   //check to see if file has read permission and that there is data in the buffer
    if (m->_wbuf->_buf!=NULL && m->_df!=-1) {
        
        if (m->_wbuf->_w <= m->_wbuf->size) {
            char *buf = (char *)malloc(1);
            char b = i+'0';
            char *z = &b;
            int x = mwrite((void*)z, 1, m); // x holds how much data is returned.
            if (x==-1) {
                return -1;
            }
            return 1;
        }
        
    }
    return -1;
}

