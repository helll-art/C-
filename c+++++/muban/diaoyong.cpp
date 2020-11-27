#include<iostream>
using namespace std;

/* 普通函数与函数模板的区别

1.普通函数调用可以发生隐式类型转换
2.函数模板 用自动类型推导，不可以发生隐式类型转换
3.函数模板 用显示指定类型，可以发生隐式类型转换 */

int myAdd01(int a,int b)
{
    return a + b;
}
template<typename T>
T myAdd02(T a, T b)
{
    return a + b;
}

int main(void)
{
    int a = 10,b = 20;
    cout << myAdd01(a,b) << endl;
    char c = 'a',d = 'e';
    cout << myAdd02<char>(c,a) << endl;

}