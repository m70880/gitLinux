#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;
void* thread_begin(void* arg){
    (void)arg;
    cout<<endl<<"i am thread arg: "<<endl;
    //exit(12);
    pthread_exit((void*)12);

    return (void*)123;
}
int main(){
    pthread_t tid=0;
    pthread_create(&tid,NULL,thread_begin,NULL);
    cout<<"i am a man "<<endl;
    void * ret;
    pthread_join(tid,&ret);
    sleep(1);
    cout<<"thread had quit ,code is :"<<(int)ret<<endl;
    return 0;
}
