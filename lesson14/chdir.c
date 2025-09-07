/*
    #include <unistd.h>
    int chdir(const char *path);
        作用：修改进程的工作目录
            比如在/home/chan 启动了一个可执行的程序a.out，进程的工作目录 /home/chan
        参数：
            path: 需要修改的工作目录
        返回值：
            On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.
    
    #include <unistd.h>
    char *getcwd(char *buf, size_t size);
        作用：获取当前工作目录
        参数：
            - buf: 存储的路径，指向一个数组(传出参数)
            - size: 数组大小
        返回值：
            返回指向的一块内存，这个数据就是第一个参数
            
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    char buf[128];
    getcwd(buf, sizeof(buf));
    printf("当前的工作目录是：%s\n", buf);

    //修改工作目录
    int ret = chdir("b");
    if(ret == -1) {
        perror("chdir");
        return -1;
    }
    printf("修改后的工作目录是：b\n");

    //创建一个新文件
    int fd = open("chdir.txt", O_WRONLY|O_CREAT, 0664);
    if(fd == -1) {
        perror("open");
        return -1;
    }
    close(fd);

    //获取当前的工作路径

    char buff[128];
    getcwd(buff, sizeof(buff));
    printf("当前的工作目录是：%s\n", buff);
    return 0;
}