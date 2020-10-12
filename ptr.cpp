#include<iostream>
#include<string>
using namespace std;
/*
指针
int i;
int * p; 指向int型的指针
const int i;
const int * i;    指向int型常量的指针
const int i;
const int *const p = &i;   指向int型常量的指针，只能指向i
常量指针 表示指向一个常量，常量的值不能修改  指向可以改变
指针常量 表示只能指向初始化时的数据名，该数据名的值可以修改，但是指针的指向不能修改
*/
int main(void)
{
    int i = 100,j = 20;
    int * p1 = &i;
    cout << "*p1 = " << *p1 << endl;
    p1 = &j;
    cout << "p1 = " << *p1 << endl;
    cout << "*******************************" << endl;
    const int a = 100, b = 20;
    const int * p2 = &a;
    cout << "*p2 = " << *p2 << endl;
    p2 = &b;
    cout << "*p2 = " << *p2 << endl;
    const int m = 100,n = 20;
    cout << "*******************************" << endl;
    const int *const p3 = &m;
    cout << "p3 = " << *p3 << endl;
    //p3 = &n;
    cout << "p3 = " << * p3 << endl;
    int x = 100,y = 20;
    int * const p4 = &x;
    x = 300;
    cout << "p4 = " << *p4 << endl;
    //p4 = &y;
    cout << "p4 = " << *p4 << endl;
    int &q = x;
    x= 60;
    cout << "q = " << q << endl;


    
}