/*
    #include <unistd.h>
    #include <sys/types.h>
    int truncate(const char *path, off_t length);
        作用：缩减或者扩展文件的尺寸至指定的大小
        参数：
            - path: 需要修改的文件的路径
            - length: 最终文件需要变成的大小
        返回值：
            On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main() {
    int ret = truncate("b.txt", 5);
    if(ret == -1) {
        perror("truncate");
        return -1;
    }
    printf("修改文件大小成功\n");
    return 0;
}