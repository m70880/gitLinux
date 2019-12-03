#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
using namespace std;
int main(){
    FILE*fp=fopen("myfile","r");
    if(!fp){
       perror("fopen error!\n");
    }
    char buff[1024];
    const char* pc="hello world!\n";
    while(1){
        ssize_t s=fread(buff,1,strlen(pc),fp);
        if(s>0){
            buff[s]=0;
            printf("%s",buff);
        }
        if(feof(fp)){
            break;
        }
    }
    fclose(fp);
    return 0;
}
