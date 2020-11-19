#include<iostream>
using namespace std;

class Myint
{
    friend ostream& operator << (ostream & cout,Myint p，int);
    friend ostream& operator << (ostream & cout,Myint &p);
private:
    int Number ;
public :

    Myint(int a)
    {
        Number  = a;
    }

    Myint& operator++()
    {
        this ->Number ++;
        return *this;
    }
    Myint operator++(int)
    {
        Myint temp = * this;
        this -> Number ++;
        return temp;
    }

};

ostream& operator << (ostream & cout,Myint &p)
{
    cout << p.Number ;
    return cout;
}

ostream& operator << (ostream & cout,Myint p,int)
{
    cout << p.Number ;
    return cout;
}


//++ -- 为什么不能写在类外

int main(void)
{
    Myint i = 10;
    i++;
    ++i;
    cout << ++i << endl;
    cout << i++ << endl;

}