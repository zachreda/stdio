//
//  mile.h
//  stdio
//
//  Created by Zach Reda on 10/16/21.
//

#ifndef mile_h
#define mile_h

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "buffer.h"


typedef struct mile mile;
typedef struct mile {
    int _df; //file descriptor (-1 is bad)
    char _mode; // r=0 | w=1 , append is a special write
    readbuff *_rbuf;
    writebuff *_wbuf;
    
};

mile *mopen(char *name, char *mode);
int mread(void *b, int len, mile *m);
int mwrite(void *b, int len, mile *m);
int mclose(mile *m);
int flush(mile *m);
void freeReadBuffer(mile *m);


#endif /* mile_h */
