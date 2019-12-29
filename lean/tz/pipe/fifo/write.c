#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    printf("before open\n");
    int fd = open("./myfifo",O_WRONLY | O_CREAT);
    printf("after open\n");
    if(fd<0){
        perror("open");
        return 1;
    }
    while(1){
        printf("->:");
        fflush_unlocked(stdout);
        char buf[1024]={0};
        read(0,buf,sizeof(buf)-1);
        ssize_t n=write(fd,buf,sizeof(buf)-1);
        if(n<0){
            perror("write");
        }
    }
    close(fd);
    return 0;
}
