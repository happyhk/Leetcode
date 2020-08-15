/*
单例模式本质就是一个类只准实例化一个对象，这其实意思就是将构造函数私有化，然后通过调用静态成员函数中的静态指针去实例化对象。
主要分为懒汉模式和恶汉模式，然后考虑到多线程的资源占用问题，所以需要进行加锁和解锁的操作。
*/


/*
懒汉模式：就是只有当调用静态成员函数，才会去实例化一个对象
具体代码如下
*/

#include "thread.h"

class A{
private:
    A(){
        pthread_mutex_init(&mtx, 0);
    }
public:
    static pthread_mutex_t mtx;
    static A* getInfo(){
        pthread_mutex_lock(&mtx);
        static A obj;
        pthread_mutex_unlock(&mtx);
        return &obj;
    }
};

pthread_mutex_t A::mtx;

/*
接下来就是饿汉模式了，不过有没有调用静态成员函数，都会先实例化好函数，这就不需要锁了。
*/

class A{
    private:
    A(){
        
    }
    static A* p;
    public:
    static A* getInfo(){
        return p;
    }
};
A* A::p = new A();

int main(){
    A* p = A::getInfo();
    cout<<p<<endl;
}







