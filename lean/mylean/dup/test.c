#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
int main(){
    //建立管道
   int fd[2];
   int ret=pipe(fd);
   if(ret<0){
       perror("pipe");
       return 1;
   }
   //分流，子进程写，父进程读
    pid_t pid=fork();
    if(pid==0){
        //child
        const char* arr="hello world!\n";
        write(fd[1],arr,strlen(arr));
        
    }
    else if(pid>0){
        //father
       wait(NULL); 
       char arrRead[1024]={0};
       size_t size = read(fd[0],arrRead,sizeof(arrRead)-1);
       arrRead[size]=0;
       printf("%s",arrRead);
    }
    else{
        perror("fork");
        return 1;
    }
    return 0;
}
