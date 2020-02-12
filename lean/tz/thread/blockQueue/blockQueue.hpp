#pragma once 
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <vector>

#define CAPATION 10

template<class T>
class blockQueue{
    private:
        std::vector<T> queue_;
        size_t head_;
        size_t tail;
        size_t max_size_;
        sem_t lock;
        sem_t blank; 
        sem_t elem;
    public:
        blockQueue(size_t max_size)
            :queue_(max_size),head_(0),tail(0)
             ,max_size_(max_size){
                 sem_init(&lock,0,1);
                 sem_init(&blank,0,max_size);
                 sem_init(&elem,0,0);
             }
        void Push(const T& data){
            // 插入元素，每次需要申请一个空格资源
            // 如果没有空格资源（信号量为0），则说明队列已经满了
            // 满了就在Push中产生阻塞
            //std::cout<<"Protect wait block"<<std::endl;
            sem_wait(&blank);
            //std::cout<<"Protect wait lock"<<std::endl;
            sem_wait(&lock);//互斥
            //std::cout<<"Protect doing"<<std::endl;
            queue_[tail] = data;
            ++tail;
            ++max_size_;
            sem_post(&lock);
            sem_post(&elem);
        }
        void Pop(T& data){
            //删除元素，
            //如果没有容量资源（信号量为0），则说明队列为空
            //空了就在Pop中产生阻塞
            //std::cout<<"Consume wait elem "<<std::endl;
            sem_wait(&elem);
            //std::cout<<"Consume wait lock"<<std::endl;
            sem_wait(&lock);
            //std::cout<<"Consume doing"<<std::endl;
            data = queue_[head_];
            ++head_;
            --max_size_;
            sem_post(&lock);
            sem_post(&blank);
        }
        ~blockQueue(){
            sem_destroy(&lock);
            sem_destroy(&blank);
            sem_destroy(&elem);

        }
};
