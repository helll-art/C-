#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class Person
{
    public :
    Person(T1 name ,T2 age);
    void showPerson();
    
    T1  name;
    T2 age;
};
//构造函数类外实现
template<class T1,class T2>
Person<T1,T2> :: Person(T1 name ,T2 age)
{
    this -> name = name;
    this -> age = age;
}
template<class T1,class T2>
void Person<T1,T2> :: showPerson()
{
    cout << name << "  " << age << endl;
}
int main(void)
{
    Person<string,int>p("sunwukong",100);
    p.showPerson();
}