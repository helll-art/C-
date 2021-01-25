#include<iostream>
#include<string>
using namespace std;

class MyInteger
{
    friend ostream & operator << (ostream & cout,MyInteger a);
    public :
        MyInteger()
        {
            Num = 0;
        }
        MyInteger(int num)
        {
            Num = num;
        }
        MyInteger& operator = (MyInteger  a)
        {
            this -> Num = a.Num;
            return *this;
        }
        MyInteger operator + (MyInteger & a)
        {
            MyInteger temp;
            temp.Num = this -> Num + a.Num;
            return temp;
        }
        //递增运算符重载
        //a++
        //++a
        MyInteger& operator++()
        {
            this -> Num ++;
            return *this;
        }
        //a.operator++(NULL); a ++
        MyInteger operator++(int)
        {
            MyInteger temp;
            temp.Num = this-> Num ;
            this -> Num ++;
            return temp;
        }
        bool operator==(MyInteger &a)
        {   
            if(this -> Num == a.Num)
                return true;
            else 
                return false;
        }
        bool operator!=(MyInteger & a)
        {
            if(this -> Num != a.Num)
                return true;
            else 
                return false;
        }
        int getNum()
        {
            return Num;
        }
    private : 
        int Num;
};

ostream & operator << (ostream & cout,MyInteger a)
{
    cout << a.Num ;
    return cout;
}
void test01()
{
    MyInteger a = 10;
    MyInteger b = 20;
    MyInteger c = 30;
    MyInteger d = a + b + c; 
    cout << d << endl <<  b << endl;
    cout << ++(++a) << endl; 
    cout << a++ << endl;
    cout << a << endl;
    if(a == b)
    {
        cout << "a == b" << a << b << endl;
    }
    if(a != b)
    {
        cout << "a != b" << a << b << endl;
    }
    
}
int main(void)
{
    test01();
}