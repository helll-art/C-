#include<iostream>
using namespace std;

class Myint
{
    friend void test01();
    //friend Myint& operator ++ (Myint &p);
    //friend Myint& operator ++ ();
public:
    Myint()
    {
        Number = 0;
        cout << "无参函数创建" << endl;
    }
    Myint(int number)
    {
        cout << "有参函数创建" << endl;
        Number = number;
    }
    Myint(Myint &p)
    {
        cout << "拷贝函数创建" << endl;
        Number = p.Number;
    }
    Myint operator ++ ()
    {
        this -> Number ++;
        return *this;
    }

    Myint operator ++(int)
    {
        Myint temp;
        temp = *this;
        this -> Number ++;
        return temp;
    }

    int Number;
};
/*
Myint& operator ++ (Myint &p)
{
    p.Number++;
    return p;
}*/

ostream & operator << (ostream & cout ,Myint p)
{
    cout << "Number = " << p.Number;
    return cout;
}
void test01()
{
    Myint p(200);
    cout << p << endl;
    ++(++p);
    cout << p.Number << endl;   
    cout << p++ << endl;
    p++;
    cout << p.Number << endl;
    cout << ++p << endl;
}
int main(void)
{
    test01();
}