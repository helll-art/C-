#include<iostream>
#include<string>
using namespace std;

class Base
{
    public :
    static int m_A;
};
class Son : public Base
{
    public :
    static int m_A;
};
int Base :: m_A = 50;
int Son :: m_A = 20;

int main(void)
{
    Son son;
    cout << son.Base :: m_A << endl;
    //cout << Base :: m_A << endl;
    //cout << Son :: m_A << endl;
}

