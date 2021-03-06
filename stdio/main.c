#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "mile.h"
#include "smile.h"

void test_read1() {
    fprintf(stderr,"==================================\n");
    fprintf(stderr, "Test Reading...\n");
    mile *m1= mopen("t1r.dat", "r");
    char *buf = (char *)malloc(10);
    memset((void *)buf, '\0', 10);
    int nr;
    while ((nr = mread((void *)buf, 4, m1)) > 0) {
        fprintf(stderr,"read:>%s<\n",buf);
        memset((void *)buf, '\0', 10);
    }
    mclose(m1);
    free(buf);
    fprintf(stderr, "Done Test Reading\n");
    fprintf(stderr,"==================================\n");
}

void test_write1() {
    fprintf(stderr,"==================================\n");
    fprintf(stderr, "Test Writing...\n");
    mile *m2 = mopen("t1w.dat", "w");
    char *buf = (char *)malloc(100);
    strcpy(buf,"This is a test of write\nline 2\n");
    fprintf(stderr, "writing:%s\nwhich is %d bytes\n",buf, (int)strlen(buf));
    int nw = mwrite((void *)buf, strlen(buf), m2);
    fprintf(stderr,"wrote: %d bytes\n",nw);
    mclose(m2);
    free(buf);
    fprintf(stderr, "Done Test Writing\n");
    fprintf(stderr,"==================================\n");
}

void test_append1() {
    fprintf(stderr,"==================================\n");
    fprintf(stderr, "Test Appending...\n");
    mile *m2 = mopen("t1w.dat", "a");
    char *buf = (char *)malloc(100);
    strcpy(buf,"This is a test of append\nline 2\n");
    fprintf(stderr, "writing:%s\nwhich is %d bytes\n",buf, (int)strlen(buf));
    int nw = mwrite((void *)buf, strlen(buf), m2);
    fprintf(stderr,"wrote: %d bytes\n",nw);
    mclose(m2);
    free(buf);
    fprintf(stderr, "Done Test Appending\n");
    fprintf(stderr,"==================================\n");
}

void test_copy1() {
    fprintf(stderr,"==================================\n");
    fprintf(stderr, "Test Copy File...\n");
    mile *m1= mopen("t1c.dat", "r");
    mile *m2 = mopen("t2c.dat", "w");
    char *buf = (char *)malloc(10);
    memset((void *)buf, '\0', 10);
    int nr;
    while ((nr = mread((void *)buf, 4, m1)) > 0) {
        fprintf(stderr,"read:>%s<\n",buf);
        fprintf(stderr, "writing:%s\nwhich is %d bytes\n",buf, (int)strlen(buf));
        int nw = mwrite((void *)buf, nr, m2);
        fprintf(stderr,"wrote: %d bytes\n",nw);
        memset((void *)buf, '\0', 10);
    }
    mclose(m1);
    mclose(m2);
    free(buf);
    fprintf(stderr, "Done Test Copy File\n");
    fprintf(stderr,"==================================\n");
}

void test_readi() {
    fprintf(stderr,"==================================\n");
    fprintf(stderr, "Test Read Int...\n");
    mile *m3 = mopen("t3i.dat", "r");
    
    int *a;
    int x = mread_int(a,m3);
    fprintf(stderr,"Read:%d\n",a);
    a = mread_int(a,m3);
    fprintf(stderr,"Read:%d\n",a);
    a = mread_int(a,m3);
    fprintf(stderr,"Read:%d\n",a);

    mclose(m3);
    fprintf(stderr, "Done Test Read Int\n");
    fprintf(stderr,"==================================\n");
}

//void test_writei() {
//    fprintf(stderr,"==================================\n");
//    fprintf(stderr, "Test Write Int...\n");
//    mile *m4 = mopen("t4i.dat", "w");
//
//    int a = 1234;
//    int nw = mwrite_int(a,m4);
//    mwrite("\n",1,m4);
//    fprintf(stderr,"Wrote:%d which is %d bytes\n",a,nw);
//    a = -2345;
//    nw = mwrite_int(a,m4);
//    mwrite("\n",1,m4);
//    fprintf(stderr,"Wrote:%d which is %d bytes\n",a,nw);
//    a = 987;
//    nw = mwrite_int(a,m4);
//    mwrite("\n",1,m4);
//    fprintf(stderr,"Wrote:%d which is %d bytes\n",a,nw);
//
//    mclose(m4);
//    fprintf(stderr, "Done Test Read Int\n");
//    fprintf(stderr,"==================================\n");
//}

void test_large() {
    fprintf(stderr,"==================================\n");
    fprintf(stderr, "Test Copy File...\n");
    const int size = 250;
    mile *m1= mopen("p1c.dat", "r");
    mile *m2 = mopen("p2c.dat", "w");
    char *buf = (char *)malloc(size);
    memset((void *)buf, '\0', size);
    int nr;
    while ((nr = mread((void *)buf, size-10, m1)) > 0) {
        fprintf(stderr,"read:>%s<\n",buf);
        fprintf(stderr, "writing:%s\nwhich is %d bytes\n",buf, (int)strlen(buf));
        int nw = mwrite((void *)buf, nr, m2);
        fprintf(stderr,"wrote: %d bytes\n",nw);
        memset((void *)buf, '\0', size);
    }
    mclose(m1);
    mclose(m2);
    free(buf);
}

int main(int argc, char *argv[]) {

    //test_read1(); //works
    //test_write1(); //works
    //test_append1(); //works
     // test_copy1(); //works
    //test_readi();
    //test_writei();
    test_large(); //works


    return 0;
}


