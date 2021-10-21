//
//  smile.h
//  stdio
//
//  Created by Zach Reda on 10/18/21.
//

#ifndef smile_h
#define smile_h

#include "mile.h"

int mputc(int c, mile *m);
int mgetc( mile *m);
int mungetc(int c, mile *m);
int mread_int(mile *m);
int mwrite_int(int *i, mile *m);

#endif /* smile_h */
