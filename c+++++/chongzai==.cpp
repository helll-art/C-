#include<iostream>
#include<string>

using namespace std;
class Person
{
    public:
        int age;
        string name;
    
    Person()
    {
        int age = 0;
        name = "null";
    }
    Person(int m_age,string m_name)
    {
        age = m_age;
        name = m_name;
    }
    bool operator==(Person &p)
    {
        if(this -> age == p.age && this -> name == p.name)
            return true;
        else 
            return false;
    }
};
bool operator!=(Person &p1,Person &p2)
{
    if(p1.age == p2.age && p1.name == p2.name)
        return false;
    else 
        return true;
}
int main(void)
{
    Person p1;
    Person p2(20,"helei");
    if(p1 != p2)
    {
        cout << "两者bu相等" << endl;
    }
    else 
    {
        cout << "两者不相等" << endl;
    }
}