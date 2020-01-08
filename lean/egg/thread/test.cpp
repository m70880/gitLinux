#include <iostream>
#include <pthread.h>
using namespace std;

void* thread_name(void *arg){
    std::cout<<"helow world!"<<endl;
    return NULL;
}

int main(){
    pthread_t tid;
    pthread_create(&tid,NULL,thread_name,NULL);
    return 0;
}









