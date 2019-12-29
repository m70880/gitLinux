#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
    int fd = open("./myfifo",O_RDONLY);    
    if(fd<0){
        perror("open");
        return 1;
    }
    while(1){
        char buf[1024]={0};
        ssize_t n=read(fd,buf,sizeof(buf)-1);
        if(n<0){
            perror("read");
        }
        if(n==0){
            return 0;
        }
        buf[n]='\0';
        printf("%s\n",buf); 
    }
    return 0;
}
