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
A.gcc -c -fpic add.c sub.c mult.c div.c 
# -fpic表示得到与位置无关的目标文件
gcc -shared add.o sub.o mult.o div.o -o libcalc.so
# -shared生成动态库libcalc.iso
B.但是如果此时直接使用 gcc main.c -o main -I ./include/ -L ./lib/ -l calc，然后执行main会报错
    chan@chan-virtual-machine:~/Linux/lesson06/library$ ./main
    ./main: error while loading shared libraries: libcalc.so: cannot open shared object file: No such file or directory
加载动态库的时候找不到该动态库libcalc.so文件,使用ldd(list dynamic dependencies)命令检查动态库依赖关系
    chan@chan-virtual-machine:~/Linux/lesson06/library$ ldd main
            linux-vdso.so.1 (0x00007ffc96fb0000)
            libcalc.so => not found
            libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x0000752f43400000)
            /lib64/ld-linux-x86-64.so.2 (0x0000752f43839000)
发现libcalc.so并没有被找到。
C.如何定位共享库文件呢？
    当系统加载可执行代码时候，能够知道其所依赖的库的名字，但是还需要知道绝对路径。此时就需要系统的动态载入器来获取该绝对路径。
对于e1f格式的可执行程序，是由ld-linux.so来完成的。
它先后搜索elf文件的DT_RPATH段 -> 环境变量LD_LIBRARY_PATH -> /etc/ld.so.cache文件列表 -> /lib/，/usr/lib目录找到库文件后将其载入内存。

    



*/