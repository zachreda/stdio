#include <stdio.h>
#include "mile.h"



int main(int argc, const char * argv[]) {
    char *mode = 'r';
    char *name = "text.txt";
    mile *file = mopen(name, mode);
    mclose(file);
    
    
    return 0;
}
