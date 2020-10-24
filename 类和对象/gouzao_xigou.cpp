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
        cout << "Person无参构造函数调用" << endl;

    }
    
    Person(const Person &a)
    {
        age = a.age;
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
void test01()
{
    
    //Person P1;
    
    Person P2(10);
    cout << "p2 = " << P2.age << endl;
    //Person P3(P2);
    //栈上实现，推出函数自动处理
}
void test02(Person P)
{
    
}
/*
    创建对象的时候会自动进行构造函数的调用
    
*/
Person doWork()
{
    Person p;
    p.age = 10;
    cout << "p 的地址为 " << &p << endl;
    return p;
}
int main(void)
{
 //   test01();
   // cout << "......." << endl;
    //隐式构造
    //Person p2 = 100;
    //显示构造
    //Person p2 = Person(100);
    //cout << "p2 = " << p2.age << endl;
    //Person p;
    //test02(p2);
    
    Person q = doWork();
    cout << "q 的地址为 " << &q << endl;
    q.age = 555;
    cout << "q.age = " << q.age << endl;
    cout << "............." << endl;
    Person qq;
    qq = doWork();
    cout << "qq 的地址为 " << &qq << endl;
    int *p;
    p = new int(2001);
    cout << *p << endl;
    int &b = *p;
    delete p;
    cout << b << endl;

}