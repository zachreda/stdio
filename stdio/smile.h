//
//  sMILE.h
//  stdio
//
//  Created by Zach Reda on 10/18/21.
//

#ifndef sMILE_h
#define sMILE_h

#include "MILE.h"

int mputc(int c, MILE *m);
int mgetc( MILE *m);
int mungetc(int c, MILE *m);
int mread_int(MILE *m);
int mwrite_int(int i, MILE *m);

#endif /* sMILE_h */
