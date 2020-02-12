#include <iostream>
#include <unistd.h>
#include <pthread.h>
void* thread_run(void*arg){
    char* name = (char*)arg;
    while(1){
    std::cout <<name<<"is runing ..."<<std::endl;
    sleep(1);

    }
}
int main(){
    pthread_t tid;
    pthread_create(&tid,NULL,thread_run,(void*)"thread 1");
    pthread_detach(tid);
    sleep(2);

    void*ret;
    pthread_join(tid,NULL);//线程等待，获取线程退出时的退出码，传到ret中。
    pthread_cancel(tid);   //当进程被取消时返回-1，即全1

    std::cout<<"ret :"<<(int)ret<<std::endl;
    return 0;
}
