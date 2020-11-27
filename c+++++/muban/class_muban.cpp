#include<iostream>
using namespace std;
#include<string>

/*
类模板可以有一个默认参数，
如果传了，就是用传的类型，如果没有，就是用默认类型

template<class NameType,class AgeType = int>

Person <string > p("孙悟空",1000); 
*/
template<class NameType,class AgeType>

class Person
{
    public :
    NameType name;
    AgeType age;
    Person(NameType name,AgeType age)
    {
        this -> name = name;
        this -> age = age;
    }
    void showPerson()
    {
        cout << "name : " << name << "   age = " << age << endl;
    }
    
};
void test01()
{
    //类模板无法使用自动类型推导,必须使用显示指定类型的方式，使用类模板
    //Person p("孙悟空",1000); 
    Person<string,int> p("sunwukong",1000);
    p.showPerson();
}
int main(void)
{
    test01();
}