#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* ThreadEntry(void* arg){
    (void)arg;
    int count=10;
    while(1){
        printf("in threadentry ,%lu\n",pthread_self());
        
    }
    return NULL;
}
int main(){
    pthread_t tid;
    pthread_create(&tid,NULL,ThreadEntry,NULL);
    while(1){
        printf("main : -----------------\n");
        sleep(1);
    }
    return 0;
}
