#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

int key=0x12345;
int main(){
    int shmid = shmget(key,1024,IPC_CREAT | 0664);
    void* lp = shmat(shmid,NULL,0);
    while(1){
        printf("%s\n",(char*)lp);
        sleep(1);
    }
    return 0;
}
