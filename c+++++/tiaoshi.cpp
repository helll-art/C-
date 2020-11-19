#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
    ofstream ofs;
    ofs.open("./message.txt",ios :: out);
    if(!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
        return 1;
    }
    string name = "hlll";
    ofs << name << endl;
}