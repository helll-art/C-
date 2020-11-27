//类模板对象做函数参数
#include<iostream>
#include<string>
using namespace std;

/*
    类模板实例化出对象，向函数传参的方式
    一共有三种传入方式：
    1.指定传入的类型   直接显示对象的数据类型
    2.参数模板化      将对象中的参数变为模板进行传递
    3.整个类模板化    将这个对象类型 模板化进行传递

*/

template<class T1,class T2>
class Person
{
    public :
        T1 name;
        T2 age;
        Person(T1 name ,T2 age)
        {
            this -> name =name;
            this -> age = age;
        }
        void showPerson()
        {
            cout << this -> name << "  " << this -> age << endl;
        }
};
//类模板做函数参数，指定传入的类型
void printPerson1(Person<string,int> & p)
{
    p.showPerson();
}
void test01()
{
    Person<string,int>p("sunwukong",100);
    printPerson1(p);
}

//2.参数模板化
template<class T1,class T2>
void printPerson2(Person<T1,T2>&p)
{
    p.showPerson();
    cout << "T1 的类型为:" << typeid(T1).name() << endl;
    cout << "T2 的类型为:" << typeid(T2).name() << endl;
}
void test02()
{
    Person<string,int>p("zhubajie",100);
    printPerson2(p);
}

//3.整个类模板化
template<class T>
void printPerson3(T &p)
{
    p.showPerson();
    cout << "T的数据类型为:" << typeid(T).name() << endl;
}
void test03()
{
    Person<string ,int> p ("tangseng",30);
    printPerson3(p);
}
int main(void)
{
    test01();
    test02();
    test03();
    //cout << typeid(char).name() << endl;
}