#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigHandler(int signo){
    printf("\n###### [%d] signo had be Init !   ######\n",signo);
    
    signal(signo,SIG_DFL);
    sleep(2);
}
int main(){
    struct sigaction newSet,oldSet;
    newSet.sa_flags = 0;
    newSet.sa_handler = sigHandler;
    //初始化信号集
    sigemptyset(&newSet.sa_mask);
    //修改制定信号的处理动作
    sigaction(SIGINT,&newSet,&oldSet);
    while(1){
        printf("hello world!\n");
        sleep(1);
    }
    return 0;
}
