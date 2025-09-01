/*
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    int open(const char *pathname, int flags, mode_t mode);
        参数:
            - pathname: 要创建的文件的路径
            - flags: 对文件操作的权限和其他的设置
                - 必选项: O_RDONLY, O_WRONLY, or O_RDWR 互斥的
                - 可选项: O_CREAT 文件不存在，创建新文件
                - mode: 八进制的数，表示创建出的新的文件的操作权限，比如： 0775 (0代表八进制，7代表用户权限，7代表用户所在组的权限，5代表其他组的用户权限)
                最终的权限是: mode & ~umask
                    umask的作用是抹去某些权限
                    umask 与 当前用户有关
                    ~umask = 0777-umask = 0777-0002 = 0775
                    最终的权限是: 0777 & 0775 = 0775
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    //创建一个新的文件
    int fd = open("create.txt", O_RDWR | O_CREAT, 0777);
    if(fd == -1) {
        perror("open");
    }
    //关闭
    close(fd);
    return 0;
}