#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int main(){
    
    //阻塞------------------------------------------
    sigset_t set,oldset;
    //int sigemptyst(sigset_t *set);
    //清空set所有信号
    sigemptyset(&set);
    //int sigfillset(sigset_t *set)
    //将所有信号添加到set集合中
    //int sigaddset(sigset_t *set,int sigum);
    //将sigum信号添加到set集合中
    //int sigdelset(sigset_t *set, int sigum);
    //将sigum信号从set集合中移除
    sigfillset(&set);
    sigprocmask(SIG_BLOCK,&set,&oldset);
    printf("pres enter to continue\n");
    getchar();
    sigprocmask(SIG_UNBLOCK,&set,NULL);
    sigprocmask(SIG_SETMASK,&oldset,NULL);
    return 0;
    //------------------------------------------------

    int i=10;
    while(i--){
        printf("hello world!\n");
        sleep(1);
    }
    
}
