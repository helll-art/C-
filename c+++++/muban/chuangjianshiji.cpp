#include<iostream>
#include<string>
using namespace std;

//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成的
class Person1
{
    public :

    void func1()
    {
        cout << "调用func1 " << endl;
    }
};
class Person2
{
    public :
    void func2()
    {
        cout << "调用func2" << endl;
    }
};

template < class T >
class MyClass
{
    public :
    T obj;
        void fun1()
        {
            obj.func1();
        }
        void fun2()
        {
            obj.func2();
        }
};
int main(void)
{
    MyClass< Person1 >mc;
    mc.fun2();
}
