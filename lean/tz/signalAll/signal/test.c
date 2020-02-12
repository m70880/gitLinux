#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

struct sigaction act,old;

void sigcb(int signo){
    printf("\nrecv :%d\n",signo);
    sigaction(SIGINT,&old,NULL);
}
int main(){
    act.sa_handler = sigcb;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGINT,&act,&old);
    
    int i=1;
    while(i++){
        printf("[%d]hello world!\n",i);
        sleep(1);
    }
    
}
