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

   

};

ostream & operator << (ostream & cout ,Person &p)
{
    cout << "Number1 = " << p.Number1 << endl;
    cout << "Number2 = " << p.Number2 ;
    return cout;
}

void test01()
{
    Person p(20,30);
    cout << p << "Hello World "<< endl;
    
}
int main(void)
{
    test01();
}