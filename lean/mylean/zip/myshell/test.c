#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

char command[1024]={0};

int do_face(){
    memset(command,0x00,1024);
    printf("[dumenglin'shell by heself]$");
    fflush_unlocked(stdout);
    if(scanf("%[^\n]%*c",command)==0){
        getchar();
        return -1;
    }
    return 0;
}
char** do_prase(){
    int i=0;
    char* p=command;
    static char* ret[1024];
    
    while((p = strtok(p," "))!=NULL){
        ret[i]=p;
        p=NULL;
        i++;
    }
    ret[i]=NULL;
    return ret;
}
int do_exec(char**argv){
    pid_t b=fork();
    if(b==0){
        //child
        execvp(argv[0],argv);
    }
    else {
        wait(NULL);
    }
    return 1;    
}
int main(){
    char **argv;
    while(1){
        do_face();
        argv=do_prase();
        do_exec(argv);
    }
    return 0;
}
