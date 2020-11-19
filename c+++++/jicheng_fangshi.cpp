#include<iostream>
#include<string>

using namespace std;

class Father
{
    public :
        int A;
    Father()
    {
        A = 200;
        cout << "Father 创建 "  << endl;
     }
     ~Father()
     {
         cout << "Father 销毁" << endl;
     }
        string F_name;
    protected:
        string F_room;
    private :
        string F_money;
};

class Mather 
{
    public : 
    string name;

    Mather()
    {
        cout << "Mather 创建" << endl;
    }
    ~Mather()
    {
        cout << "Mather 销毁 " << endl;
    }
};
class Child : public Father
{
    public : 
        string C_name;
        int A;
    Child()
    {
        A = 100;
        cout << "Child 创建" << endl;
    }
    ~Child()
    {
        cout << "Child 销毁" << endl;
    }
    void test()
    {
        //this -> F_room = 'hll';

    }
    Mather mather;
};


//父类中所有非静态成员属性都会被子类继承下去
//父类中私有成员属性，是被编译器隐藏了，因此访问不到，但是确实被继承下去了
//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数
//如果想访问到父类中被隐藏的同名成员函数，需要加上作用域  
void test01()
{
    cout << "sizeof Child = " << sizeof(Child) << endl;
    cout << "sizeof string = " << sizeof(string ) << endl;
}
int main(void)
{
    //栈区先进后出
    Child child;
    test01();
    cout << child.A << endl;
    cout << child.Father :: A << endl;
}