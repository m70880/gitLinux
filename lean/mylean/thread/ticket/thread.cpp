#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;
pthread_mutex_t lock;
int count=1000;
void* thread_func(void* arg){
    cout<<"----------------------------------------"<<endl;
    int thread_number=*((int*)arg);
    delete (int*)arg;
    while(1){
        pthread_mutex_lock(&lock);
        if(count>0){
            usleep(1000);
            count--;
            cout<<thread_number<<"thread get"<<count<<endl;
        }
        else{
            pthread_mutex_unlock(&lock);
            break;
        }
        pthread_mutex_unlock(&lock);
        usleep(1000);
    }
    return arg;
}

int main(){
    pthread_t tid[3]; 
    //创建线程
    for(int i=0;i<3;i++){
        pthread_create(&tid[i],NULL,thread_func,(void*)new int(i));
    }
    for(int i=0;i<3;i++){
        pthread_join(tid[i],NULL);
    }
    return 0;
}
