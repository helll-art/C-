#include<iostream>
#include<string>

using namespace std;

class Person 
{
    public:     
        string  name;   
      
    Person(){}
    Person(string name)
    {
        this -> name = name;
    }

    void operator()(string m_name)
    {
        cout << "name = " << m_name << endl;
    }
    
};

class Add
{
    public:
        int number1;
        int number2;
    Add(){}
    int operator()(const int a,const int b)
    {
        return a + b ;
    }
};
int main(void)
{
    Person myPrint;
    myPrint("helei");
    Add myAdd;
    int a = 100;
    int b = 20;
    int sum = myAdd(10,20);
    cout << "sum = " << sum << endl;
    cout << Add()(10,20) <<endl;
}