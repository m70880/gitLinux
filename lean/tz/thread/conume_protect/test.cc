#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include<vector>

pthread_mutex_t lock;
pthread_cond_t cond;

std::vector<int> data;

void* Consume(void* arg){
    (void)arg;
    //将数据取出来
    while(1){
        pthread_mutex_lock(&lock);
        while(data.empty()){
            //1.先释放锁
            //2.等待条件就绪（等待其他线程调用pthread_cond_signal）
            //3.如果有条件就绪了，则从新获取锁
            //注意：加了wait之后最大的意义在于，如过没有资源，消费者就不用一直空转，不必浪费cpu资源
            pthread_cond_wait(&cond,&lock);
        }
        int consume = data.back();
        data.pop_back();
        std::cout << "Conume a data :" << consume<<std::endl;
        pthread_mutex_unlock(&lock);
        usleep(3*1000);
    }
    return NULL;
}
int a=0;
void* Protect(void* arg){
    (void)arg;
    while(1){
        usleep(10*10);
        pthread_mutex_lock(&lock);
        data.push_back(a++);
        std::cout<<"protect a data :"<<a<<std::endl;
        usleep(10*10);
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&cond);
    }
    return NULL;
}

int main(){
    pthread_mutex_init(&lock,NULL);
    pthread_cond_init(&cond,NULL);

    pthread_t tid1,tid2,tid3,tid4;
    pthread_create(&tid1,NULL,Consume,NULL);
    pthread_create(&tid2,NULL,Protect,NULL);
    pthread_create(&tid3,NULL,Consume,NULL);
    pthread_create(&tid4,NULL,Protect,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    while(1){
        sleep(1);
    }
    return 0;
}
