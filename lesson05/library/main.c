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
A.如果此时直接gcc main.c，由于main.c与head.h不在同一目录会报错
    chan@chan-virtual-machine:~/Linux/lesson05/library$ gcc main.c -o app
    main.c:2:10: fatal error: head.h: No such file or directory
        2 | #include "head.h"
        |          ^~~~~~~~
    compilation terminated.
解决方法有两个 (1)移动main.c到include (2)使用 -I来指定库目录位置
B.采用 -I解决上述问题，但会遇到下面的报错提示，原因是main中调用函数未引用
    chan@chan-virtual-machine:~/Linux/lesson05/library$ gcc main.c -o app -I ./include/ 
    /usr/bin/ld: /tmp/ccW9805c.o: in function `main':
    main.c:(.text+0x41): undefined reference to `add'
    /usr/bin/ld: main.c:(.text+0x66): undefined reference to `subtract'
    /usr/bin/ld: main.c:(.text+0x8b): undefined reference to `multiply'
    /usr/bin/ld: main.c:(.text+0xb0): undefined reference to `divide'
    collect2: error: ld returned 1 exit status
C.采用 -l指定库文件名称，但是库还是找不到可以再加一个 -L去指定库位置
gcc main.c -o app -I ./include/ -l calc -L ./lib/
*/