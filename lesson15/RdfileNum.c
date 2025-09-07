/*
    man 3 opendir
    // 打开一个目录
    #include <sys/types.h>
    #include <dirent.h>
    DIR *opendir(const char *name);
        参数：
            - name: 打开的目录名
        返回：
            DIR * 类型, 一个目录流
            失败返回NULL

    man 3 readdir
    // 读取目录的数据
    #include <dirent.h>
    struct dirent *readdir(DIR *dirp);
        - 参数： dirp是opendir返回的目录流
        - 返回：
            dirent结构体, 代表读取到的文件信息
            读取到了末尾或者失败了返回NULL
            struct dirent {
               ino_t          d_ino;       
               off_t          d_off;       
               unsigned short d_reclen;    
               unsigned char  d_type;      
               char           d_name[256]; 
           };

    
    man 3 closedir
    // 关闭目录
    #include <sys/types.h>
    #include <dirent.h>
    int closedir(DIR *dirp);

*/
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//读取某个目录下的所有普通文件的个数
int FileNum(const char *path);
int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("%s path\n", argv[0]);
        return -1;
    }

    printf("普通文件个数为%d\n", FileNum(argv[1]));

    return 0;
}

// 用于获取目录下所有所有普通文件的个数
int FileNum(const char *path) {
    int cnt = 0;
    // 1.打开目录
    DIR *dir = opendir(path);
    if(dir == NULL) {
        perror(NULL);
        exit(0);
    }
    // 2.循环读取dir
    struct dirent *ptr;
    while((ptr=readdir(dir)) != NULL) {
        // 获取名称 (目的是过滤掉 ./ 和 ../)
        char *dname = ptr->d_name;
        if(strcmp(dname,".") == 0||strcmp(dname,"..") == 0) {
            continue;
        }
        // 判断是普通文件还是目录

        // 如果是目录
        if(ptr->d_type == DT_DIR) {
            // 递归读取这个目录, 需要在path后加上/dname
            char newpath[256];
            sprintf(newpath, "%s/%s", path, dname);
            cnt += FileNum(newpath);
        }

        // 如果是普通文件
        if(ptr->d_type == DT_REG) {
            cnt ++;
        }
    }
    closedir(dir);
    return cnt;
}