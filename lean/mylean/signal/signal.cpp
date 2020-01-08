#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <sys/shm.h>

using namespace std;

void signalback(int sig){
    (void)sig;
    cout<<"signal is doing.....:"<<sig<<endl;
    
}

int main(){
    signal(2,signalback);
    signal(45,signalback);


    return 0;
}
