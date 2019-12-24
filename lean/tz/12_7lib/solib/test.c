#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
extern int Add(int x,int y);
int main(){
    int ret=Add(1,3);
    while(ret--){
    printf("i also finish a work: %d\n",ret);
    }
    return 0;
}

