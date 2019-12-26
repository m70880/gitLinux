#include <stdio.h>
#include<sys/wait.h>
#include <string.h>
#include <unistd.h>

char commond[1024]={0};
void do_face(){
    printf("[杜孟林的myshell/]$");
    fflush(stdout);
    memset(commond,0,1024);
    gets(commond);
}
char** do_analy(){
    static char* ret[32]={0};//注意返回后，栈中的元素将不存在，所以必须将其设置成静态变量
    char* p=commond;
    int i=0;
    while((p=strtok(p," "))!=NULL){
        ret[i]=p;
        p=NULL;
        i++;
    }
 //    i=0;
 //   while(ret[i]!=NULL){
 //       printf("ret:%s\n",ret[i]);
 //       i++;
 //   }
    ret[i]=0;
    return ret;
}

int do_exec(char** com){
    int ret=fork();
    if(ret==0){
        //child
        execvp(com[0],com);
    }
    else if(ret>0){
        //father
        waitpid(ret,NULL,0);
    }
    return 0;
}
int main(){
    while(1){
    do_face();
    char ** com=do_analy();
    do_exec(com);
    }
    return 0;
}
