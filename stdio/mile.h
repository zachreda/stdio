//
//  MILE.h
//  stdio
//
//  Created by Zach Reda on 10/16/21.
//

#ifndef MILE_h
#define MILE_h

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "buffer.h"


typedef struct MILE MILE;
typedef struct MILE {
    int _df; //file descriptor (-1 is bad)
    char _mode; // r=0 | w=1 , append is a special write
    readbuff *_rbuf;
    writebuff *_wbuf;
    
};

MILE *mopen(char *name, char *mode);
int mread(void *b, int len, MILE *m);
int mwrite(void *b, int len, MILE *m);
int mclose(MILE *m);
int flush(MILE *m);
void freeReadBuffer(MILE *m);


#endif /* MILE_h */
