#include<iostream>
#include<string>
using namespace std;


/*
Phone构造函数执行
Person构造函数执行 
zhangsan 带的手机是 huawei
Person析构函数执行
Phone析构函数执行
类在栈中
迟到早退
*/
class Phone
{
public:
    string Phone_name;
    Phone(string name) : Phone_name(name){
        cout << "Phone构造函数执行" << endl;
    }
    ~Phone()
    {
        cout << "Phone析构函数执行" << endl;
    }

};
class Person
{
public:

    Person(string name,string phone_name) : Pname(name) , p(phone_name){
        cout << "Person构造函数执行 " << endl;
    } 
    ~Person()
    {
        cout << "Person析构函数执行" << endl;
    }



    string Pname;
    Phone p;
};
int main(void)
{
    Person qqq("zhangsan","huawei");
    cout << qqq.Pname << " 带的手机是 " << qqq.p.Phone_name << endl;
}