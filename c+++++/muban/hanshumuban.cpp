#include<iostream>
using namespace std;

void myPrint(int a,int b)
{
    cout << "调用普通函数" << endl;
}
template <typename T>
void myPrint(T a,T b)
{
    cout << "调用的是函数模板" << endl;
}
template<typename T>

void myPrint(T a,T b,T c)
{
    cout << "调用重载函数模板" << endl;
}

int main(void)
{
    int a,b;
    myPrint(a,b);
    myPrint<>(a,b);
    char c,d;
    myPrint(c,d);
    
    myPrint(a,b,b);
}