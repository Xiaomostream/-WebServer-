/*
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>

    int stat(const char *pathname, struct stat *statbuf);
        作用： 获取一个文件相关的信息
        参数： 
            - pathname: 文件路径
            - statbuf: 结构体变量，传出参数，用于保存获取到的文件信息
        返回值：
            成功：返回0
            失败：返回-1 设置errno

    int lstat(const char *pathname, struct stat *statbuf);
        作用： 获取一个文件相关的信息
        参数： 
            - pathname: 文件路径
            - statbuf: 结构体变量，传出参数，用于保存获取到的文件信息
        返回值：
            成功：返回0
            失败：返回-1 设置errno
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int main() {
    struct stat statbuf;
    int ret = lstat("b.txt", &statbuf);
    //获取软连接指向的文件信息
    //int ret = lstat("a.txt", &statbuf);
    if(ret == -1) {
        perror("stat");
    }
    printf("size: %ld\n", statbuf.st_size);
    return 0;
}