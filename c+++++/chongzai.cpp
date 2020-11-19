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
        this -> age =p.age;
        //return * this;
    }
};
//重载 +
Person operator + (Person &p,Person &q)
{
    Person z;
    z.high = new int(*p.high + *q.high);
    z.age = q.age + p.age;
    return z;
}
ostream& operator << (ostream &cout,Person &p)
{
    cout << "high = " << *p.high << endl;
    cout << "age = " << p.age ;
}


//重载cout
void test01()
{
    Person p(20,180);
    cout << p << endl;

}
void test02()
{
    Person p(20,180);
    Person q(10,140);
    Person z = p + q;
    
    cout << z << endl;
}




int main(void)
{
    test02();
}