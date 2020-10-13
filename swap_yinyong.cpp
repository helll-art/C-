#include<iostream>
using namespace std;

void swap01(int * a,int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap02(int &a ,int &b)
{
    int temp = a ;
    a = b;
    b = temp;

}
int main(void)
{
    int a = 100;
    int b = 20;
    swap01(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap02(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}