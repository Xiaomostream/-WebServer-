/*  
    man 2 access
    #include <unistd.h>
    int access(const char *pathname, int mode);
        作用：判断某个文件是否有某个权限(R_OK,W_OK,X_OK)，或者判断文件是否存在(F_OK)
        参数：
            - pathname: 判断的文件路径
            - mode:
                R_OK,W_OK,X_OK,F_OK 读,写,执行,文件存在
        返回值：成功返回0，失败返回1
*/
#include <unistd.h>
#include <stdio.h>

int main() {
    int ret = access("a.txt", F_OK);
    if(ret == -1) {
        perror("access");
        return -1;
    }
    printf("文件存在！！！\n");
    return 0;
}

