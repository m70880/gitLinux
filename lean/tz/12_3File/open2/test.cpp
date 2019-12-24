#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    int fd = open("myfile",O_CREAT | O_WRONLY,0664);
    if(fd<0){
        //当fd小于0则打开文件或创建文件失败
        perror("open");
        return 1;
    }
    //打开成功
    int count=10;
    const char* arr="hello world!\n\n\n";
    while(count--){
        write(fd,arr,strlen(arr));
    }
    close(fd);
    return 0;
}
