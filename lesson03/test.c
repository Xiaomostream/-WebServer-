#include <stdio.h>
int main() {
#ifdef Debug
    printf("我是小沫，啥也不会\n");
#endif
    for (int i = 1; i <= 3; i ++ ) printf("Hello GCC!!!\n");
    return 0;
}
//gcc test.c -o test -D Debug