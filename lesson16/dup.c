/*
       #include <unistd.h>
       int dup(int oldfd);
            作用：复制一个新的文件描述符，与传入的旧的文件描述符oldfd指向同一个文件
                例子：
                fd=3, int fd1 = dup(fd),
                fd指向的是a.txt，fd1指向的也是a.txt
                从空闲的文件描述符表中找一个最小的，作为新的拷贝文件

*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd = open("a.txt", O_RDWR | O_CREAT, 0644);
    int fd1 = dup(fd);
    if(fd1 == -1) {
        perror("dup");
        return -1;
    }
    printf("fd=%d fd1=%d\n", fd, fd1);
    close(fd);

    char *str = "Hello, World";
    int ret = write(fd1, str, strlen(str));
    if(ret == -1) {
        perror("write");
        return -1;
    }
    close(fd1);
    return 0;
}