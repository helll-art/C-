#include<iostream>
#include<string>
using namespace std;
/*
    构造和析构都是必须有的实现，如果我们自己不提供，编译器
    会自动进行空实现
    */
class Person
{
public:
    int age;
    /*
    构造函数没有返回值，不用写void
    函数名与类名相同
    构造函数可以有参数，可以沒有参数
    构造对象的时候，构造函数会自动调用，且只调用一次
    
    */
   Person()
    {
        cout << "Person构造函数调用" << endl;

    }
    Person(const int &a)
    {
        age = a;
        cout << "Person 拷贝函数的调用" << endl;
    }
    
    Person(int a)
    {
        age = a;
        cout << "Person 有参函数的调用" << endl;
    }

    /*
    析构函数，进行清理的操作
    没有返回值不写void
    函数名和类名相同，在名称前加～
    析构函数不可以有参数，不可以有重载
    对象在销毁前，会自动调用析构函数，而且只会调用一次
    */
   ~Person()
   {
       cout << "Person析构函数的调用" << endl;
   }
};
void test()
{
    //Person P1;
    
    Person P2(10);
    //Person P3(P2);
    //栈上实现，推出函数自动处理
}
int main(void)
{
    test();
    //Person p;
}