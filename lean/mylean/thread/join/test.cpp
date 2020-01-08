#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;
void* thread_begin(void* arg){
    cout<<"i am thread arg: "<<endl;
    sleep(1);
    return arg;

}
int main(){
    pthread_t tid=0;
    pthread_create(&tid,NULL,thread_begin,NULL);
    while(1){
        cout<<"i am a man "<<endl;
        sleep(1);
    }
    sleep(1);
    return 0;
}
