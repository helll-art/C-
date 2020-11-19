#include<iostream>
using namespace std;

class Person
{  

public:
    int *high;
    int age;

    Person(){};
    Person(int age,int high)
    {
        this -> high = new int(high);
        this -> age = age; 
    }
    Person(Person &p)
    {
        this -> high = new int(*p.high);
        this -> age = p.age;
    }
    ~Person()
    {
        if(high != nullptr)
        {
            delete high;
            high = nullptr;
        }
    }
    void operator = (Person &p)
    {
        this -> high = new int(*p.high);
        this -> age = p.age;
        //return * this;
    }
};
int main(void)
{
    Person p(20,180);
    Person q;
    q = p;
    cout << q.age << *p.high << endl;
}