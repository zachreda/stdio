#include <stdio.h>
#include "mile.h"

int main(int argc, const char * argv[]) {
    char *mode = 'w';
    char *name = "out.txt";
    mile *file = mopen(name, mode);
    
    char *buf = "je";
    
    int x = mwrite(buf, 2, file);
    return 0;
}
