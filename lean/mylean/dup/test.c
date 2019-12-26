#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
int main(){
    ssize_t fd = open("./file",O_WRONLY);
    dup2(fd,1);
    printf("hellow : %d\n",1024);
    return 0;
}
