#include "cp.hpp"
using namespace std;

void* customer_rotinue(void* arg)
{    
    (void)arg;
    BlockQueue* bqp = (BlockQueue*)arg;
    int data;
    for(;;){
        bqp->PopData(data);
        cout<<"consume done ,data is:"<<data<<endl;
    }
    return NULL;
}
void* protect_rotinue(void* arg){
    (void)arg;
    BlockQueue* bqp = (BlockQueue*)arg;
    for(;;){
        int data =rand()%100 + 1;
        bqp->PushData(data);
        cout<<"protect done ,data is: " << data << endl;
        usleep(100 * 1000);
    }
    return NULL;
}
int main(){
    BlockQueue *bqp = new BlockQueue(num);
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,customer_rotinue,(void*)bqp);
    pthread_create(&tid2,NULL,protect_rotinue,(void*)bqp);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    
    return 0;
}









