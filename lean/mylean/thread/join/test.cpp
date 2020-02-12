#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;
void* thread_begin(void* arg){
    (void)arg;
    cout<<"i am thread arg: "<<endl;
    sleep(1);
    return (void*)123;

}
int main(){
    pthread_t tid=0;
    //pthread_create(&tid,NULL,thread_begin,NULL);
    cout<<"i am a man "<<endl;
    void * ret;
    int ll = pthread_join(tid,&ret);
    cout<<"thread had quit ,code is :"<<ll<<endl;
    //cout<<"thread had quit ,code is :"<<(int)ret<<endl;
    return 0;
}
