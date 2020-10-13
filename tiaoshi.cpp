#include<iostream>
using namespace std;
int g_a = 200;
void func(int a ,int b)
{
    cout << "形参a所在的地址为: " << &a << endl;
    cout << "形参b所在的地址为: " << &b << endl;
}
int main(void)
{
    int a1 = 100;
    int b1 = 200;
    const int a2 = 50;
    const int b2 = 50;
    const  string str1 = "hello World";
    string str2 = "Hello world";
    int * p2 = new int (20);
    int * p = new int(10);
    const int &x = 100;
    static int xx = 20;
    cout << "全局变量a所占的内存地址为:" << &g_a << endl;
    cout << "静态变量所占用的内存地址为：" << &xx << endl;
    cout << "局部变量a所占的内存地址为: " << &a1 << endl;
    cout << "局部变量b所占的内存地址为：" << &b1 << endl;
    cout << "常量a所占的内存地址为：   " << &a2 << endl;
    cout << "常量b所占的内存地址为：   " << &b2 << endl;
    cout << "字符串常量1所占的内存地址为:" << &str1 << endl;
    cout << "字符串2所占的内存地址为:" << &str2 << endl;
    cout << "引用所占用的内存地址为:" << &x << endl;
    func(10,10);
    cout << "手动开辟的内存空间所占用的地址为:" << p2 << endl;
    
    

}
