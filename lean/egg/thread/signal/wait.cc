#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_cond_t cond;
pthread_mutex_t mute;

void* thread_1(void* arg){

    while(1){
        pthread_cond_wait(&cond,&mute);
        cout<<"hello world!"<<endl;
    }
    return NULL;
}
void* thread_2(void* arg){

    while(1){
        pthread_cond_signal(&cond);
        sleep(1);
    }
    return NULL;
}


int main(){
    pthread_mutex_init(&mute,NULL);
    pthread_cond_init(&cond,NULL);

    pthread_t tid;
    pthread_t tid2;
    pthread_create(&tid,NULL,thread_1,NULL);
    pthread_create(&tid2,NULL,thread_2,NULL);

    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);

    pthread_mutex_destroy(&mute);
    pthread_cond_destroy(&cond);
        sleep(5);
    return 0;
}

