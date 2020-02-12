#include "threadPool.hpp"

class MyTask :public Task{
public:
    MyTask(int id):id_(id){}
    void Run(){
        //执行用户自定义得功能
        cout<<"Run had doing a thread :"<< id_<<endl;
    }
private:
    int id_;
};
void* ThreadEntry(void* arg){
    (void)arg;
    cout<<"hell"<<endl;
    return NULL;
}
int main(){
    ThreadPool pool(10);
    for (int i = 0;i < 200; i++){
        pool.AddTask(new MyTask(i));
    }
    while(1){
        sleep(1);
    }
    return 0;
}
