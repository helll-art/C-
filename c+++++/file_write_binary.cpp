#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Person
{
    public:
        int age;
        string name;
        Person(int age,string name)
        {
            this -> age = age;
            this -> name = name;
        }

};

int main(void)
{
    Person p(18,"zhangsan");
    ofstream ofs("../Person.txt", ios :: in | ios :: binary);
    //ofs.write的第一个参数，要的就是字符型指针
    ofs.write((const char *) &p,sizeof(Person) );
    

    ofs.close();
}