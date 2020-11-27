
#include <iostream>
#include<string>
using namespace std;
class Person
{
    public :
        int age;
        string name;
        Person() {}
        Person(string name ,int age)
        {
            this -> name = name;
            this -> age = age;
        }
};