#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    int ret=fork();
    if(ret>0){
        //father
        
    }
    else if(ret==0){
        //children
        //exec
        execl("/usr/bin/ls","ls","-l",NULL);
    }
    else{
        //error
        perror("fork");
    }

    return 0;
}
