#include<iostream>
using namespace std;
 int Person :: a = 100;
class Person
{
public:
    //string a;
    //char aa;
    static int a;
    int b;
    void func(){}
};
/*
    成员函数和成员变量是分开存储的
    静态变量必须初始化
    静态成员函数和静态成员变量和成员函数不属于类内

    总结一句话：只有非静态成员变量存在类内
*/

int main(void)
{
    Person p;
    cout << "size of = " << sizeof(p) << endl;
    cout << p.a << endl;
}