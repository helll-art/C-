#include<iostream>
#include<string>
using namespace std;


//语法 ： class 子类 ： 继承方式  父类
//子类也称为派生类
//父类也称为基类
class BasePage
{
public:
    void head()
    {
        cout << "头部" << endl;
    }
    void foot()
    {
        cout << "底部" << endl;

    }
    void left()
    {
        cout << "左侧" << endl;
    }

};

class Java : public BasePage
{
    public :
    void content()
    {
        cout << "Java content" << endl;
    }
};
class Python : public BasePage
{
    public :
    void content()
    {
        cout << "Python content" << endl;
    }
};
class CPP : public BasePage
{
    public :
    void content()
    {
        cout << "CPP content" << endl;
    }
};

int main(void)
{
    Python p;
    Java j;
    CPP c;
    p.head();
    p.left();
    p.foot();
    p.content();
    j.head();
    j.left();
    j.foot();
    j.content();
}
