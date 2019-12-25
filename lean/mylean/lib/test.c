#include <stdio.h>
#include "stdio.h"
extern int Add(int a,int b);
int main(){
    int a=3;
    int b=2;
    int c=Add(a,b);
    while(c--){
        printf("i review a my favourite work :%d\n",c);
    }
    return 0;
}
