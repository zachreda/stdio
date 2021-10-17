//
//  buffer.h
//  stdio
//
//  Created by Zach Reda on 10/17/21.
//

#ifndef buffer_h
#define buffer_h

#include <stdio.h>

typedef struct buffers buffers;
typedef struct buffers {
    void *_buf; // buffer
    int _len; //length of the buffer
    void *_rp; //pointer for reading
    void *_wp; //pointer for writing
    void *_cp; //current pointer
};

#endif /* buffer_h */
