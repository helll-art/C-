#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class Person;
template <class T1,class T2>
void printPerson2(Person<T1,T2> p)
{
    cout << "类外实现" <<  p.name << "  " << p.age << endl;
}

/*
    全局函数类内实现    直接在类内声明友元即可
    全局函数类外实现    需要提前让编译器知道全局函数的存在

    1.在声明时，需要加上尖括号
        friend void printPerson2<>(Person<T1,T2> p);
    2.在开头需要声明要使用的类，
        template<class T1,class T2>
        class Person;
    3.书写函数
        template <class T1,class T2>
        void printPerson2(Person<T1,T2> p)
        {
            cout << p.name << "  " << p.age << endl;
        }
 */
template<class T1,class T2>
class Person
{
    friend void printPerson2<>(Person<T1,T2> p);
    
    //friend void printPerson(Person<T1,T2> p)
    friend void printPerson(Person<T1,T2> p)
    {
        cout << "类内实现" << p.name << "  " << p.age << endl;
    }
public :

    Person(T1 name ,T2 age)
    {
        this -> name = name ;
        this -> age = age;
    }
private:

    T1 name;
    T2 age;
};


void test01()
{
    Person<string,int> p("Tom",20);
    printPerson(p);
    printPerson2(p);
}
int main(void)
{
    test01();
    
}