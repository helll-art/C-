#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Person
{
    public :
    string name;
    int age;
};
int main(void)
{   
     ifstream ifs;
     ifs.open("../Person.txt",ios :: in | ios :: binary);

     if(!ifs.is_open())
     {
         cout << "文件打开失败" << endl;
         return 0;
     }
     char buf[1024] = "\0";
     while(ifs.getline(buf,sizeof(buf)))
     {
         cout << buf << endl;
     }

     ifs.close();
}