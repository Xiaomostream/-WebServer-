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
1.使用gcc -c以只汇编但不链接的方式来生成.o目标文件
gcc -c add.c div.c mult.c sub.c 
2.将.o文件进行打包，使用ar工具(archive)
ar rcs libcalc.a add.o div.o mult.o sub.o
r插入 c创建 s索引
3. tree
.
├── include
│   └── head.h
├── lib
│   └── libcalc.a
├── main.c
└── src
    ├── add.c
    ├── div.c
    ├── mult.c
    └── sub.c
如果此时直接gcc main.c，由于main.c与head.h不在同一目录会报错
    chan@chan-virtual-machine:~/Linux/lesson05/library$ gcc main.c -o app
    main.c:2:10: fatal error: head.h: No such file or directory
        2 | #include "head.h"
        |          ^~~~~~~~
    compilation terminated.
解决方法有两个 (1)移动main.c到include (2)使用 -I来指定库目录位置
采用 -I解决上述问题，但会遇到下面的报错提示，原因是main中
*/