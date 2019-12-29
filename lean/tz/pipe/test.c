#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    //使用pipe函数创建一对文件描述符，通过这一堆文件描述符描述
    //节能操作内核中的管道
    int fd[2];
    int ret = pipe(fd);
    if(ret<0){  // return --->  //0:ok      //-1:error
        perror("pipe");
        return 1;
    }
    //f[0] -> 读数据
    //f[1] -> 写数据
    ret=fork();
    if(ret==0){//子进程进行写入，父进程进行读取，要保证父进程先读，否则父进程则在read处等待，若子进程等待，父进程结束，子进程被1号进程托管，也会终止
        //child
        char arr[1024]="hello world!";
        write(fd[1],arr,strlen(arr));
        char readbuf[1024]={0};
        ssize_t n = read(fd[0],readbuf,sizeof(readbuf)-1);
        readbuf[n]='\0';
        printf("child read :%s\n",readbuf);
    }
    else if(ret>0){
        //father
        char readbuf[1024]={0};
        ssize_t n = read(fd[0],readbuf,sizeof(readbuf)-1);
        readbuf[n]='\0';
        printf("father read :%s\n",readbuf);
        
    }
    close(fd[0]);
    close(fd[1]);
    return 0;
}
