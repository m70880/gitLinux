#include <iostream>

#include <stdio.h>
#include <unistd.h>
#include <string.h>
using namespace std;
int main(){
    FILE*fp=fopen("myfile","w");
    if(!fp){
       perror("fopen error!\n");
    }
    const char* pc="hello world!\n";
    int count=5;
    while(count--){
        fwrite(pc,strlen(pc),1,fp);
    }
    fclose(fp);

    return 0;
}
