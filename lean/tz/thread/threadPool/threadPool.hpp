#pragma once 

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "BlockQueue.hpp"
using namespace std;
//线程池对象启动的时候会创建一组线程
//每个线程都需要完成一定的任务（执行一定的逻辑，这个逻辑是由调度者来决定的）
//任务是一段代码，可以用函数来表示j

class Task{
public:
    Task(){
    }
    virtual void Run(){
        cout<<"base Run:"<<endl;
    }
    virtual ~Task(){

    }
};
class ThreadPool{
public:
    // n -> 创建线程的数量
    ThreadPool(int n):queue_(n),work_count_(n){
        for (size_t i = 0 ;i < work_count_;i++){
            // 创建出若干的线程
            //cout<<"ThreadPool:: create:"<< i <<endl;
            pthread_t tid;
            pthread_create(&tid,NULL,thread_func,this);
           //cout<<"ThreadPool:: create over!:"<< i <<endl;
            workers_.push_back(tid);
            //cout<<"push"<<endl;
        }
    }
    ~ThreadPool(){
        for(size_t i =0; i < workers_.size();i++){
            cout<<"ThreadPool:: cancel:"<< i <<endl;
            pthread_cancel(workers_[i]);
        }
        for(size_t i = 0;i < workers_.size();i++){
            pthread_join(workers_[i],NULL);
        }
    }
   //使用线程时，可以由用户增加一些任务，
   //由线程池去执行
    void AddTask(Task* task){
        (void)task;
        queue_.Push(task);
    }
private:
    static void* thread_func(void* arg){
        ThreadPool* pool = (ThreadPool*)arg;
        while(true){
            Task* task = NULL;
            pool->queue_.Pop(task);
            task->Run();
            delete task;
            usleep(100*1000);    
        }
        return NULL;
    }
private:
    BlockQueue<Task*> queue_;
    std::vector<pthread_t> workers_;
    size_t work_count_;
};





