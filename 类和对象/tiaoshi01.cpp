#include<iostream>
using namespace std;

class Person
{
public:
    int age;
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

   ~Person()
   {
       cout << "Person析构函数的调用" << endl;
   }
};
Person doWork()
{
    Person p;
    p.age = 10;
    cout << "p 的地址为 " << &p << endl;
    return p;
}
int main(void)
{
    Person p = doWork();
    cout << &p << endl;
}