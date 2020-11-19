#include<iostream>
using namespace std;

class Person 
{
    public :
        int *p_age;
        int high;

    Person(int age,int high)
    {
        p_age = new int(age);
        this -> high = high;
    }
    Person(Person &p)
    {
        this -> p_age = new int(*p.p_age);
        this -> high = p.high;
    } 

    ~Person()
    {
        if(this ->p_age != nullptr)
        {
            delete p_age;
            p_age = NULL;
        }
    }
    Person& operator= (Person &q)
    {
        if(q.p_age != nullptr)
        {
            this -> p_age = new int (*q.p_age);
            
        }
        this -> high = q.high;
        return *this;
    }
};





//创建类的时候进行深拷贝

void test01()
{
    Person p(20,190);
    Person q(10,130);
    Person z(5,60);
    z = q = p;
    cout << *q.p_age << endl << q.high << endl;
    cout << *z.p_age << endl << z.high << endl;
    
}
int main(void)
{
    test01();
    
}
//p = q;
