#include<iostream>
using namespace std;


//test01()
/*
    默认情况下，c++编译器至少给一个类添加三个函数
    1.默认构造函数（无参，函数体为空）
    2.默认析构函数（无参，函数体为空）
    3.默认拷贝构造函数，对属性进行复制

    构造函数调用规则如下：
    如果用户定义有参构造函数，c++不再提供无参构造函数
    如果用户定义拷贝构造函数，c++不再提供有参构造函数和无参构造函数
    注意，不再提供的是编译器自身的
*/

//test02()   深拷贝与浅拷贝
class Person 
{
public:
    int age;
    int weigh;
    int  *high;
    //初始化列表初始化属性
    //Person(int a,int b) :age(a),weigh(b){}
    Person()
    {
        cout << "无参构造函数调用" << endl;
        age = 20;
    }
    
    Person(int a,int b)
    {
        cout << "有参构造函数调用 " << endl;
        age = a;
        high = new int(b);
    }
    
    Person(const Person &a)
    {
        age = a.age;
        high = new int();
        *high = *a.high;
        cout << "拷贝构造函数调用 " << endl;

    }
    
    ~Person()
    {
        if(high != nullptr)
        {
            delete high;
            high = nullptr;
        }

        
        cout << "析构函数调用" << endl;
    }
};

/*
    如果属性又在堆区创建的，一定要自己写拷贝函数，防止浅拷贝带来的问题
    浅拷贝带来的问题
    被拷贝的对象为p 要拷贝的对象为q
    加入p中包含指针，对对象进行析构函数时，会重复释放两次内存，因为他们存的地址是相同的
    对一个地址进行两次释放属于非法操作
    解决方法：     解决堆区重复释放的问题（深拷贝操作）
    自己写一个拷贝函数
    让指针指向自己开辟的一个内存空间
    手动赋值
*/
void test02()
{
    Person p(18,180);
    Person q(p);
    cout << "p.age = \t" << p.age << "p.high = " << *p.high << endl;
    cout << "q.age = \t" << q.age << "q.high = " << *q.high << endl; 
}
void test03()
{
    Person p(18,180);
    Person q = p;
    cout << "p 的地址为 " << &p << endl;
    cout << "q 的地址为 " << &q << endl;
}

//当其他类成员作为本类的成员时，构造先构造其他类的对象，再构造自身


/*
void test01()
{
    Person p;
    Person q(1000);
    Person z(p);
}
*/
int main(void)
{
    test03();
}