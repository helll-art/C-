#include<iostream>
#include<string>
using namespace std;

/*

virtual  
    多态分为两类：
        静态多态：函数重载和运算符重载属于静态多态，重用函数名
        动态多态：派生类和虚函数实现运行时多态
    静态多态和动态多态的区别：
        静态多态的函数地址早绑定：编译阶段确定函数地址
        懂太多太的函数地址晚绑定：运行阶段确定函数地址
    多态的使用条件：
        父类指针或引用指向子类对象
 */
class Animal
{
    public :
        int name;
    //虚函数
    //地址早绑定，在编译阶段确定函数地址
    //如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定

    //动态多态的满足条件
    //1.有继承关系
    //2.子类重写父类虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Dog : public Animal
{
    public :
        int dog;

    void speak()
    {
        cout << "小狗在说话" << endl;

    }
};

class Cat : public Animal
{
    public:
        int cat;
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

void dospeak(Animal & animal)
{
    animal.speak();
}

int main(void)
{

    Cat cat;
    dospeak(cat);
    Animal animal;
    dospeak(animal);
    Dog dog;
    dospeak(dog);


}
