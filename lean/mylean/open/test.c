#include <ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(){
    int fp=open("jmp1.txt",O_WRONLY|O_CREAT,0644);
    if(fp<0){
        perror("open");
        return 1;
    }
    int count=5;
    const char* arr="hellow! \n";
    int a=strlen(arr);
    while(count--){
        write(fp,arr,a);
    }
    close(fp);
    return 0;
}
