#include <stdio.h>
#include "head.h"

int main()
{
    int a = 20;
    int b = 12;
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", subtract(a, b));
    printf("a * b = %d\n", multiply(a, b));
    printf("a / b = %f\n", divide(a, b));
    return 0;
}
/*
1.使用gcc -c以只汇编但不链接的方式来生成.o文件
gcc -c add.c div.c mult.c sub.c 
2.将.o文件进行打包，使用ar工具(archive)
ar rcs libcalc.a add.o div.o mult.o sub.o
*/