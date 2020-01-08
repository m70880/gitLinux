#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

void* thrread_try(void* arg){
    while(1){
        cout<<"thread : -----"<<endl;
        sleep(1);
    }
    return NULL;
}
int main(){
    pthread_t tid;
    int ret = pthread_create(&tid,NULL,thrread_try,NULL);
    if(ret!=0){
        return 1;
    }
    while(1){
        cout<<"main thread ======"<<endl;
        sleep(2);
    }
    return 0;
}
