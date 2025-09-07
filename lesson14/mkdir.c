/*
    #include <sys/stat.h>
    #include <sys/types.h>
    int mkdir(const char *pathname, mode_t mode);
        作用：创建一个目录
        参数：
            pathname: 创建的目录的路径
            mode: 权限，八进制的数
        返回值：
            return zero on success, or -1 if an error occurred (in which case, errno is set appropriately).
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
int main() {
    int ret = mkdir("a", 0777);
    if(ret == -1) {
        perror("mkdir");
        return -1;
    }
    printf("创建文件夹成功\n");
    return 0;
}