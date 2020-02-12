#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;
pthread_mutex_t lock;

int main(){
    //初始化
    pthread_mutex_init(&lock,NULL);
    
    
    return 0;
}

