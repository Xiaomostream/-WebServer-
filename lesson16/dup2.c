/*
       #include <unistd.h>
       int dup2(int oldfd, int newfd);
        作用：重定向文件描述符
            eg: oldfd指向a.txt, newfd指向b.txt
            调用函数成功后， newfd 和 b.txt做close, newfd指向了a.txt
            oldfd 必须是一个有效的文件描述符
            oldfd和newfd值相同，相当于什么也没有做
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd = open("1.txt", O_RDWR | O_CREAT, 0664);
    if(fd == -1) {
        perror("open");
    }
    
    int fd1 = open("2.txt", O_RDWR | O_CREAT, 0664);
    
    printf("fd=%d fd1=%d\n", fd, fd1);
    
    int fd2 = dup2(fd, fd1);
    if(fd2 == -1) {
        perror("dup2");
    }

    // 通过fd1去写数据，实际操作的是1.txt，而不是2.txt
    char *str = "Hello, World!";
    int ret =write(fd1, str, strlen(str));
    if(ret == -1) {
        perror("write");
    }
    printf("fd=%d fd1=%d fd2=%d\n", fd, fd1, fd2);

    close(fd);
    close(fd1);
    return 0;
}