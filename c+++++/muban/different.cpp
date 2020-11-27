#include<iostream>
using namespace std;

class Person
{
    public : 
        int age;
        string name;

        Person(int age,string name)
        {
            this -> age = age;
            this -> name = name;
        }
};
template < typename T>

bool myCompare(T &a, T & b)
{
    cout << "一般函数模板" << endl;
    if(a == b)
        return true;
    else 
        return false;
}

template <> bool myCompare(Person &p1 ,Person &p2)
{
    if(p1.age == p2.age)
        return true;
    else 
        return false;
}
int main(void)
{
    Person p1(20,"helei");
    Person p2(19,"guofan");
    bool ret = myCompare(p1,p2);
    if(ret)
    {
        cout << "a == b" << endl;
    }    
    else 
    {
        cout << "a != b" << endl;
    }
    int a = 10;
    int b = 20;
    ret = myCompare(a,b);
    if(ret)
    {
        cout << "a == b" << endl;
    }    
    else 
    {
        cout << "a != b" << endl;
    }
}
