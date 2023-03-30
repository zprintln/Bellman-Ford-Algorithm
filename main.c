// Run with: clang -Wall main.c -o main
#include <stdio.h>
#include "my_bellman.h"
#include "my_bellman_test.c"

int main() {

    printf("============ unitTest1() ================\n");
    unitTest1();
    printf("============ unitTest2() ================\n");
    unitTest2();
    printf("============ unitTest3() ================\n");
    unitTest3();
    return 0;
}
