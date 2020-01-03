#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigHandler(int signo){
    printf("\n###### [%d] signo had be Init !   ######\n",signo);
    
    signal(signo,SIG_DFL);
    sleep(2);
}
int main(){
    signal(SIGINT,sigHandler);
    while(1){
        printf("hello !\n");
        sleep(1);
    }
    return 0;
}
