//
//  buffer.h
//  stdio
//
//  Created by Zach Reda on 10/17/21.
//

#ifndef buffer_h
#define buffer_h

#include <stdio.h>
typedef struct readbuff readbuff;
typedef struct readbuff {
    void *_buf; // read buffer in memory
    int _r, _re, size; //current, end, size of buffer
};

typedef struct writebuff writebuff;
typedef struct writebuff {
    void *_buf; // read buffer in memory
    int _w, size; //might need to change later
};


#endif /* buffer_h */
