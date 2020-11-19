#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(void)
{
    ifstream ifs;
    ifs.open("chongzai_hanshu.cpp",ios :: in);
    
    //判断文件是否打开成功
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return 0;
    }
    char buf[1024] = "\0";
    string buf1;

    
    /*
        第一种方式
        不能读取空格
     while(ifs >> buf)
    {
        cout << buf << endl;
    } */


    /*
        第二种方式    
        利用字符数组进行读取
     while(ifs.getline(buf,sizeof(buf)))
    {
        cout << buf << endl;
    } */

    /*
        第三种方式
        利用字符串进行读取
     while(getline(ifs,buf1))
    {
        cout << buf1 << endl;
    } */

   /* 
        第四种方式
        利用字符进行读取
        不建议使用，char 类型不一定有符号
    char ch;
    while((ch = ifs.get()) != EOF)    // end of file
    {
        cout << ch ;
    } 


*/
    ifs.close();
}