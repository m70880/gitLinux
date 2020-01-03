#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

int key=0x12345;
int main(){
    //申请共享内存，
    //设置共享内存大小，
    //权限，
    //返回值:获取共享内存句柄
    int shmid = shmget(key,1024,IPC_CREAT | 0664);
    if(shmid < 0){
        perror("shmget\n");
        return 1;
    }
    //创建shmid_ds buf 接收共享内存信息
    struct shmid_ds buf;
    //int shmctl(int shmid, int cmd, struct shmid_ds *buf);
    //cmd:IPC_STAT :获取shmid共享内存空间的信息，将其存储在buf中
    
    shmctl(shmid,IPC_STAT,&buf);
    printf("shmid.size:->%ld\n",buf.shm_segsz);
    //shmat:获取shmid的内存地址(将共享内存地址链接到当前程序)
    //第一次创建完共享内存时，
    //它还不能被任何进程访问，
    //shmat()函数的作用就是用来启动对该共享内存的访问，
    //并把共享内存连接到当前进程的地址空间
    
    void* lp = shmat(shmid,NULL,0);
    
    if(!lp){
        perror("shmat\n");
        return 1;
    }
    while(1){
        sprintf((char*)lp,"%s","hello ! i am writing!\n");
        sleep(1);
    }
    shmdt(lp);
    shmctl(shmid,IPC_RMID,NULL);
    

    return 0;
}
