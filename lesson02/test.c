#include <stdio.h>
#define PI 3.14
int main() {
    //这是测试代码
    int sum = PI + 10;
    printf("Hello World\n");
    return 0;
}
// gcc test.c -E -o test.i
// gcc test.i -S -o test.s
// gcc test.s -s -o test.o 