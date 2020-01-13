#pragma once 

#include <unistd.h>
#include <iostream>
#include <queue>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

const int num = 6;

class BlockQueue{
    private:
        std::queue<int> bq;
        size_t cap;
        pthread_mutex_t lock;
        pthread_cond_t cond_c;
        pthread_cond_t cond_p;
    private:
        void LockQueue(){
            pthread_mutex_lock(&lock);
        }
        void UnLockQueue(){
            SignalProtect();
            pthread_mutex_unlock(&lock);

        }
        void ProtectWait(){
            SignalConsume();
            pthread_cond_wait(&cond_p,&lock);
        }
        bool IsFull(){
            return cap == bq.size();
        }
        bool IsEmpty(){
            return 0 == bq.size();
        }
        void ConsumeWait(){
            pthread_cond_wait(&cond_c,&lock);
        }
        void SignalConsume(){
            pthread_cond_signal(&cond_c);
        }
        void SignalProtect(){
            pthread_cond_signal(&cond_p);
        }
        bool IsHightWaterLine(){
            return bq.size() >= num/2;
        }
    public:
        BlockQueue(int cap1)
            :cap(cap1)
        {
            pthread_mutex_init(&lock,NULL);
            pthread_cond_init(&cond_c,NULL);
            pthread_cond_init(&cond_p,NULL);
        }

        void PushData(const int data){
           LockQueue(); 
           while(IsFull()){
               ProtectWait();
           }
           if(IsHightWaterLine()){
               SignalConsume();
               sleep(1);
           }
           bq.push(data);
           UnLockQueue();
        }

        void PopData(int & data){
           LockQueue(); 
           while(IsEmpty()){
               ConsumeWait();
           }
           data=bq.front();
           bq.pop();
           UnLockQueue(); 

        }
        ~BlockQueue(){
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&cond_c);
            pthread_cond_destroy(&cond_p);
        }
    
};
