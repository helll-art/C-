#include<iostream>
#include<string>
using namespace std;

//抽象类,没用
class Base
{
    public:
    //纯虚函数
    virtual void func() = 0;
    
    virtual void func1()
    {
        cout << "虚函数，不是纯虚函数" << endl;
    }
     void func1()
    {
        cout << "一般函数" << endl;
    }
};

/*
    抽象类是无法实例化对象
    Base b :
    new Base;
    子类必须重写父类中的纯虚函数，否则无法实例化对象
*/
class Son : public Base
{
    public:
        void func()
        {
            cout << "Son 函数调用" << endl;
        }
};
int main(void)
{
    Son s;
    s.func();
    Son * ss;
    ss = new Son;
    ss -> func();

}