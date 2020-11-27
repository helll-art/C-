#include<iostream>
#include<string>
using namespace std;
/*
    当类模板碰到继承时，需要注意一下几点
    1.当子类继承的父类是一个类模板时，子类在声明的时候，要制定出父类中T的类型
        如果不指定，编译器无法为子类分配内存
        如果想灵活制定出父类中T的类型，子类也需要变为类模板
 */
template <class T>
class Base
{
    public:
        T m;
        
};
class Son : public Base <int> 
{
    public :
        int a;
};
template<class T1,class T2>
class Son1 : public Base<T1>
{
    public :
        T2 name;
        Son1(T2 a)
        {
            name = a;
        }

    void print()
    {
        cout << "T1所占大小为 : " << sizeof(T1) << endl;
        cout << "T1的数据类型为 : " << typeid(T1).name() << endl;

        cout << "T2所占大小为 : " << sizeof(T2) << endl;
        cout << "T2的数据类型为 : " << typeid(T2).name() << endl;
        cout << "name = " << name << endl;
    }
};
int main(void)
{
    cout << "Son 的大小为 : " << sizeof(Son) << endl;
    char ch = 'a';
    Son1<int,char> p(ch);
    p.print();
}
