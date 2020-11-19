#include<iostream>
using namespace std;

class Person
{
public:
    int Number1 = 100;
    int Number2 = 100;

    Person(){};
    Person(int N1,int N2)
    {
        Number1 = N1;
        Number2 = N2;

    }
    Person(Person &p)
    {
        Number1 = p.Number1;
        Number2 = p.Number2;
    }

    Person operator + (Person &p1)
    {
        Person p2;
        p2.Number1 = this -> Number1 + p1.Number1;
        p2.Number2 = this -> Number2 + p1.Number2;
        cout << p2.Number1 << "\t" << p2.Number2 << endl;
        return p2;

    }

};
/*
Person operator + (Person &p1,Person &p2)
{
    Person p3;
    p3.Number1 = p1.Number1 + p2.Number1;
    p3.Number2 = p1.Number2 + p2.Number2;
    return p3;
}
*/
void test01()
{
    Person p1(10,20);
    Person p2(20,30);
    Person p3(60,60);
    Person p5;
    p5 = p1 + p2 + p3;
    cout << p5.Number1 << p5.Number2 << endl;
}
int main(void)
{
    test01();
}