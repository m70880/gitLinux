#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int main(){
    //kill(getpid(),9);
    abort();
    raise(9);
    alarm(2);
    int i=10;
    while(i--){
        printf("hello world!\n");
        sleep(1);
    }
    
}
