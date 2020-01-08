#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <vector>

using namespace std;
pthread_mutex_t lock;

int Ticket=1000;

void* BuyTicket(void* arg){
    while(1){
        pthread_mutex_lock(&lock);
        if(Ticket>0){
            cout<<"the thread "<<(int)arg<<"  Ticket:"<<Ticket<<endl;
            Ticket--;
            pthread_mutex_unlock(&lock);
            usleep(1000);
        }
        else{
            pthread_mutex_unlock(&lock);
            break;
        }
    }
    return (void*)NULL;
    
}

struct thread_id{
    int name;
    pthread_t tid;
};
int main(){
    int number = 10;
    vector<thread_id> th(number);
    for(size_t i=0;i<th.size();i++){
        pthread_create(&th[i].tid,NULL,BuyTicket,(void*)i);
    }
    for(size_t i=0;i<th.size();i++){
        pthread_join(th[i].tid,NULL);
    }
    return 0;
}
