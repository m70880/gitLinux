#include "blockQueue.hpp"
blockQueue<int> blq(100);

void* Consume(void* arg){
    (void)arg;
    while(1){
        int data;
       // std::cout<<"Consume before"<<std::endl;
        blq.Pop(data);
        std::cout<<"get a data :"<<data<<std::endl;
        usleep(100*1000);
    }
    return NULL;
}

void* Protect(void* arg){
    (void)arg;
    int data = 1;
    while(1){
        //std::cout<<"Protect before"<<std::endl;
       blq.Push(data);
      std::cout<<"Push a data :"<<data++<<std::endl;
        usleep(30*1000);
    }
    return NULL;
}


int main(){
    
    pthread_t tid1, tid2;
    pthread_create(&tid1,NULL,Consume,NULL);
    pthread_create(&tid2,NULL,Protect,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    
    
    return 0;
}
