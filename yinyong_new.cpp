#include<iostream>
#include<string>
using namespace std;
/*
        内存分区
    //代码区：存放函数的二进制代码，由操作系统管理
全局区：存放全局变量和静态变量以及常量
栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
堆区：有程序员分配和释放，若程序员不释放，程序结束时，有操作系统回收

不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活变成


程序运行前： 分为代码区和全局区，
程序运行后： 分为栈区，堆区
代码区：
    存放cpu执行的机器指令
    代码区是共享的，共享的目的是防止频繁的执行同一部分代码
    代码区是只读的，不能对里面的数据进行修改
全局区：
    存放全局变量，静态变量，常量
    常量区中存放const修饰的全局变量和字符串常量
栈区：
    存放函数的参数值，局部变量等
堆区：
    堆区数据有程序员管理开辟和释放
    堆区数据利用new关键字进行开辟内存

*/
int * func(int a)
{
    int *p1 = new int(a);
    //手动开辟一个数组，
    int * p = new int[10];
    //开辟一个有10个元素的整形数组
    delete [] p;
    //数组释放
    return p1;
}
int * func1(int a)
{
    int *p = &a;
    return p;
}
int& func2()
{
    static int a = 555;
    cout << "qweasdzxc" << endl;
    return a;
}
int main(void)
{
    int *p = func(10);
    cout << *p << endl;
    cout << *p << endl;
    delete p;
    cout << *p << endl;

    /*
    func1中的p是在栈区中分配的，所以退出函数会进行释放，理应不能去获取已经释放了的地址值
    但是编译器会保留一次，再次调用的时候才会出错
    */
    int *p1 = func1(20);
    cout << *p1 << endl;
    cout << *p1 << endl;

    int &a = func2();
    cout << a << endl;
    //引用函数可以作为左值，他的返回值是一个引用，函数并没有执行，只是使用了一下引用
    func2() = 666;

    cout << a << endl;

}