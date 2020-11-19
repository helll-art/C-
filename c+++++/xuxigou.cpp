#include<iostream>
#include<string>
using namespace std;


/* 父类指针在析构的时候，不会调用子类中析构函数，导致子类如果有堆区属性，会出现内存泄漏情况 
    虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
    如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
    拥有纯虚析构函数的类也属于抽象类
    虚析构和纯虚析构的共性：
        可以解决弗雷指针释放子类对象
        都需要具体的函数实现
    纯虚析构和虚析构的区别：
        如果是纯虚析构，该类属于抽象类，无法实例化对象
    */
class Animal
{
    public:
        Animal()
        {
            cout << "Animal构造函数创建" << endl;
            
        }
        /* virtual ~Animal()
        {
            cout << "Animal虚析构函数创建" << endl;
        } */
        virtual void speak() = 0;
        virtual ~Animal() = 0;
        
};
Animal :: ~Animal()
{ 
    cout << "Animal纯虚析构函数创建" << endl;
}
class Cat : public Animal
{
    public :
        Cat (string name)
        {
            cout << "Cat构造函数创建" << endl;
            this -> name = new string(name);
        }
        string *name;
        ~Cat()
        {
            if(name != nullptr)
            {
                delete name;
                name = nullptr;
            }
            cout << "Cat析构函数创建" << endl;
        }
    void speak()
    {
        cout << *name << "小猫在说话" << endl;
    }

};


void test01()
{
    Animal * animal;
    animal = new Cat("Tom");
    animal -> speak();
    delete animal;
}
int main(void)
{
    test01();
}