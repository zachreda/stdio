#include <stdio.h>
#include "mile.h"

int main(int argc, const char * argv[]) {
    char *mode = 'r';
    char *name = "text.txt";
    mile *file = mopen(name, mode);
    mile *file2 = mopen(name, mode);
    
    char *buf = (char *)malloc(10*sizeof(char));
    char *buf2 = (char *)malloc(10*sizeof(char));
    
    int x = mread(buf, 10, file);
    int x2 = mread(buf2, 10, file2);
    
    printf("Read %i bytes\n",x);
    for (int i=0; i<10; i++) {
        printf("%c\n",buf[i]);
    }
    printf("\nnew\n");
    
    for (int i=0; i<10; i++) {
        printf("%c\n",buf2[i]);
    }
    
    
    
    return 0;
}
