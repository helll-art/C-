#include<iostream>
using namespace std;

/*
    函数重载：
        1.同一个作用域下
        2.函数名称相同
        3.但是函数的参数类型不同，或者函数参数个数不同，或者顺序不同
    函数重载时，不要产生二义性
*/
//这些函数放在一起总是容易产生冲突，只能注释掉在进行执行

void func()
{
    cout << "this is func! " << endl;
}

/*
void func(int a)
{
    cout << "this is func(int a)" << endl;
    cout << a << endl;
}
*/


//形参引用
void func(int &a)
{
    cout << "this is func(int &a)" << endl;
}

void func(const int &a)
{
    cout << "this is func(const int &a)" << endl;
}

void func(int a,int b = 10)
{
    cout << "this is func(a,b = 10)" << endl;

}
void func(int a)
{
    cout << "this is func(a)" << endl;
}
int main(void)
{
    func();

  //  int &a = 10;
    //错误，10是一个常量，被存放在全局区
    //引用的数据必须被定义在栈区或堆区
   // const int &a = 19;
    //正确，因为编译器进行了优化，
   // int temp = 19;

    func(10);
    
}