#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;
int main(){
    int ret=fork();
    if(ret==0){
        //子进程
        execlp("ps","ps","-ef",NULL);
        sleep(2);
    }
    else if(ret>0){
        //父进程
        int status;
        wait(&status);
        cout<<"begin sleep"<<endl;
        cout<<"end sleep"<<endl; 
    }
    else{
        perror("fork");
    }
    return 0;
}

