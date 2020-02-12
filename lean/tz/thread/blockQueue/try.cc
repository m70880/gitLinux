#include "BlockQueue.hpp"
using namespace std;

BlockQueue<int> q(10);



void * thread_pop(void* arg){
    (void)arg;
    while(1){
        int data;
        q.Pop(data);
        cout<<"Pop data:"<<data<<endl;
        usleep(100*1000);
    }
    return NULL;
}

void * thread_Push(void* arg){
    (void)arg;
    int data = 20;
    while(1){
        q.Push(data);
        cout<<"Push data:"<<data++<<endl;
        usleep(10*1000);
    }
    return NULL;
}
int main(){
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,thread_Push,NULL);
    pthread_create(&tid2,NULL,thread_pop,NULL);
    
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    while(1){
        sleep(1);
    }

    return 0;
}
