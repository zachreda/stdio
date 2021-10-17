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
    filep->_buf = (char *)malloc(BUFSIZE*sizeof(char));
    filep->_mode = mode;
    
    
    if (mode=='r') {
        filep->_df = open(name, O_RDONLY); //open file for reading
    }
    if (mode=='w') {
        filep->_df = open(name, O_WRONLY); //open file for writing
    }
    
    return filep;
}

int mclose(mile *m){
    if (sizeof(m->_mode)!=0) {
        free(m->_buf);
        free(m);
        return 0;
    }
    
    return -1; //if there is no mode set then the file then the file is already closed
}
