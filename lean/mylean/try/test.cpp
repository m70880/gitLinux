#include <iostream>
#include <unistd.h>

using namespace std;

class Base{
public:
    int a_;
    static int b_;
    static void test(int b){
        b_ = b;
    }
};

int Base::b_ = 0;

int main(){
    Base t;
    t.test(10);
    cout<<t.b_<<endl;
    sleep(1);
}

