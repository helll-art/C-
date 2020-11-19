#include<iostream>
#include<string>

using namespace std;

//声明模板 
template <typename T>
//函数模板用typename 类模板用class
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template < class T>
//调用无参模板时必须给出一个数据类型，一个模板不进行操作无法进行使用
//比如一个一寸照片模板，不给出一个模样，无法进行提交
void func()
{
    cout << "func 调用" << endl;
}

int main(void)
{
    //int a = 10, b = 20;
    //mySwap(a,b);
    //cout << a << endl << b << endl;
    double a = 1.1,b = 2.2;
    //自动类型推导
    //mySwap(a,b);
    //显示指定类型
    mySwap<double>(a,b);
    cout << a << b << endl;
    func<double>();
}
