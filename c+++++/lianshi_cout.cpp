#include<iostream>
using namespace std;

class Person
{
    public:
    int age;
    int sex;
};
//链式编程
ostream & operator << (ostream & cout , Person &p)
{
    cout << "p.age = " << p.age << endl;
    cout << "p.sex = " << p.sex << endl;
    return cout;
}
//一般的cout类

// void operator <<(ostream & cout , Person p)
// {
//     cout << "p.age = " << p.age << endl;
//     cout << "p.sex = " << p.sex << endl;
// }
int main(void)
{
    Person p;
    p.age = 18;
    p.sex = 20;
    Person q;
    q.age = 100;
    q.sex = 200;
    cout << p << q << " hello world" << endl;
} 