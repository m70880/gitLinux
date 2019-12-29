#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    int ret=fork();
    int status;
    if(ret == 0){
        //children
        
       exit(2); 
    }
    else if(ret > 0){
        //father
       wait(&status); 
       //查看初始值status
       printf("father origin status: %d\n",status);
    
       
       //查看coredump是否存在
       printf("father coredump status: %d\n",(status >> 7) & 0x1);
       //查看子进程退出状态
       printf("father state status: %d\n",(status >> 8) & 0x7f);
    }
    else{
        perror("fork");
    }
}
