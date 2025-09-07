/*
    #include <stdio.h>

    int rename(const char *oldpath, const char *newpath);
    返回值
    On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.
*/

#include <stdio.h>
int main() {
    int ret = rename("a","b");
    if(ret == -1) {
        perror("rename");
        return -1;
    }
    printf("修改成功\n");
    return 0;
}
