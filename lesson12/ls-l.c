#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
//模拟实现 ls -l命令
//-rw-rw-r-- 1 chan chan    11  9月  6 17:51 a.txt
int main(int argc, char *argv[]) {
    //判断输入的参数是否正确
    if(argc < 2) {
        printf("%s filename\n", argv[0]);
        return 0;
    }

    //通过用户传入的文件名，调用stat获取文件信息
    struct stat statbuf;
    int ret = stat(argv[1], &statbuf);
    if(ret == -1) {
        perror("stat");
        return 0;
    }

    //1. 获取文件类型与文件权限
    char perms[11] = {0}; //用于保存文件类型与文件权限
    switch (statbuf.st_mode & S_IFMT) {
        case S_IFLNK:
            perms[0] = 'l';
            break;
        case S_IFREG:
            perms[0] = '-';
            break;
        case S_IFBLK:
            perms[0] = 'b';
            break;
        case S_IFDIR:
            perms[0] = 'd';
            break;
        case S_IFCHR:
            perms[0] = 'c';
            break;
        case S_IFIFO:
            perms[0] = 'p';
            break;
        case S_IFSOCK:
            perms[0] = 's';
            break;
        default:
            perms[0] = '?';
            break;
    }
    
    // 判断文件的访问权限
    perms[1] = (statbuf.st_mode & S_IRUSR) ? 'r':'-';
    perms[2] = (statbuf.st_mode & S_IWUSR) ? 'w':'-';
    perms[3] = (statbuf.st_mode & S_IXUSR) ? 'x':'-';
    perms[4] = (statbuf.st_mode & S_IRGRP) ? 'r':'-';
    perms[5] = (statbuf.st_mode & S_IWGRP) ? 'w':'-';
    perms[6] = (statbuf.st_mode & S_IXGRP) ? 'x':'-';
    perms[7] = (statbuf.st_mode & S_IROTH) ? 'r':'-';
    perms[8] = (statbuf.st_mode & S_IWOTH) ? 'w':'-';
    perms[9] = (statbuf.st_mode & S_IXOTH) ? 'x':'-';

    // 2.硬连接数
    int linknum = statbuf.st_nlink;

    // 3.文件所有者: 可以通过statbuf.st_uid得到uid, 然后通过getpwuid来获取用户名; man 3 getpwuid可查看
    char * fileUser = getpwuid(statbuf.st_uid)->pw_name;

    // 4.文件所在组: 可以通过statbuf.st_gid得到gid, 然后通过getgrgid来获取用户名; man 3 getpwgid可查看
    char * fileGrp = getgrgid(statbuf.st_gid)->gr_name;

    // 5.获取大小
    long int fileSize = statbuf.st_size;

    // 6.获取修改时间  statbuf.st_mtime:从1980年到修改时间的一个秒数，使用ctime转换，以换行结尾
    char * time = ctime(&statbuf.st_mtime);
    char mtime[512] = {0};
    strncpy(mtime, time, strlen(time)-1);
    char buf[1024];
    sprintf(buf, "%s %d %s %s %ld %s %s", perms, linknum, fileUser, fileGrp, fileSize, mtime, argv[1]);
    printf("%s\n", buf);
    return 0;
}
