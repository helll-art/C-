#include<iostream>
using namespace std;
void operator << (ostream &cout ,Person &p);
class Person;

class Person
{
public:
    int age;
    int sex;
    Person()
    {
        cout <<"无参构造函数创建" << endl;

    }
    Person( int aage,int ssex)
    {
        
        this -> age = aage;
        this -> sex = ssex;
        cout << "有参构造函数创建" << endl;
       

    }
    Person(Person &p)
    {
        age = p.age;
        sex = p.sex;
        cout << "拷贝构造函数创建" << endl;
    }

    ~Person()
    {
        cout << "析构函数创建" << endl;
    }
    
   // Person operator+(Person p)
    Person Person_Add_Person (Person p)
    {
        Person q;
        q.age = this -> age + p.age;
        q.sex = this -> sex + p.sex;
        return q;
    } 
};



/*    通过全局函数进行重载 
Person operator+(Person &p,Person &q)
{
    Person temp;
    temp.age = p.age + q.age;
    temp.sex = p.sex + q.sex;
    return temp;
} */

/* 
一个类怎么和int型数据进行相加
对上面的全局函数进行修改，将第二个参数改为int */
/*
    两个类进行相加
    自己构造函数，用自己的函数名
        z = q.Person_Add_Person(p);
    也可以利用系统构造的提供的函数名
        operator+
    将函数名替换为operator+，现在就可以对两个类进行直接相加，相加的内容是你自己函数写的内容
        z = q + p;
*/
void test01(void)
{
    Person p(18,1);
    cout << p.age <<"\t"<< p.sex << endl;
    Person q(p);
    cout << q.age << "\t" << q.sex << endl;
    Person z;
    z = q.Person_Add_Person(p);
    //z = q + p;
    cout << z.age << "\t";
    cout << z.sex << endl;
    
}


//如何让cout输出整个类
void test02()
{
    Person p(18,2);
    cout << p;
}
/*
void operator<<(ostream &cout ,Person &p)
{
    cout << "age = \t" << p.age << "sex = " << p.sex << endl;
}
*/
int main(void)
{
   test02();
}