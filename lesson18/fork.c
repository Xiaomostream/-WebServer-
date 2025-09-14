/*
    #include <sys/types.h>
    #include <unistd.h>

    pid_t fork(void);
        函数的作用：用于创建子进程
        返回值：
            fork的值会返回两次。一次是在父进程中，一次是在子进程中。
                在父进程中返回创建的子进程的id, 在子进程中返回0
            如何区分父进程和子进程：通过fork的返回值
            在父进程中返回-1，表示创建子进程失败，并且设置errno 
            失败的两个主要原因是：1.进程数已经达到上限 2.系统内存不足
*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    //创建子进程
    pid_t pid = fork();

    //判断是父进程/子进程
    if(pid > 0) {
        printf("pid : %d\n", pid);
        // 如果大于0，返回的是创建的子进程的pid，当前是父进程
        printf("I am parent process, pid : %d, ppid : %d\n", getpid(), getppid());
    }
    else if(pid == 0) {
        printf("pid : %d\n", pid);
        // 当前是子进程
        printf("I an child process, pid : %d, ppid : %d\n", getpid(), getppid());
    }


    //for循环
    for (int i = 0; i < 3; i ++ ) {
        printf("i : %d, pid : %d\n", i, getpid());
        sleep(1);
    }
    return 0;
}