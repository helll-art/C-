#include<iostream>
#include<string>
#include "MyArray.hpp"
#include "person.hpp"
using namespace std;
//出现candidate expects xx argument, 0 provided这种情况，说明是可能是调用了默认的构造函数
void test01()
{
    MyArray<int> arr(10);
    cout << "请输入要添加元素的个数 : " ;
    int num;
    cin >> num;
    int number;
    for(int i = 0 ; i < num ; ++ i)
    {
        cin >> number;
        arr.Push(number);
    }

    cout << "arr Capacity = " << arr.getCapacity() << endl;
    cout << "arr Size = " << arr.getSize() << endl;
    
    for(int i = 0 ; i < arr.getSize() ;++ i)
    {
        cout << arr[i] << endl;
    }
    arr.Pop();
    arr.Pop();
    /* arr.Pop();
    arr.Pop(); */
    cout << "arr Capacity = " << arr.getCapacity() << endl;
    cout << "arr Size = " << arr.getSize() << endl;
    for(int i = 0 ; i < arr.getSize() ;++ i)
    {
        cout << arr[i] << endl;
    }
}
//Person类

void printPerson(MyArray<Person> & p)
{
    for(int i = 0 ; i < p.getSize() ; ++ i)
    {
        cout << "姓名 ：" << p[i].name << "     年龄 : " << p[i].age << endl;
    }
    
}
void test02()
{
    MyArray<Person> arr(10);
    cout << "请输入要添加元素的个数 : " ;
    int num;
    cin >> num;
    int number;
    string name;
    int age;
    Person p;
    for(int i = 0 ; i < num ; ++ i)
    {
        cout << "请输入第 " << i + 1 << "个姓名 ：" ;
        cin >> name;
        cout << "请输入第 " << i + 1 << "个年龄 ：" ;
        cin >> age;
        p.name = name;
        p.age = age;
        arr.Push(p);
    }
    cout << "arr Capacity = " << arr.getCapacity() << endl;
    cout << "arr Size = " << arr.getSize() << endl;
    
    printPerson(arr);
    arr.Pop();
    arr.Pop();
    /* arr.Pop();
    arr.Pop(); */
    cout << "arr Capacity = " << arr.getCapacity() << endl;
    cout << "arr Size = " << arr.getSize() << endl;
    printPerson(arr);

}

//连等赋值
void test03()
{
    MyArray<int> arr(10);
    cout << "请输入要添加元素的个数 : " ;
    int num;
    cin >> num;
    int number;
    for(int i = 0 ; i < num ; ++ i)
    {
        cin >> number;
        arr.Push(number);
    }

    cout << "arr Capacity = " << arr.getCapacity() << endl;
    cout << "arr Size = " << arr.getSize() << endl;
    MyArray<int> arr1(10);
    MyArray<int> arr2(10);
    arr2 = arr1 = arr;

    arr2.Pop();
    arr2.Pop();
    cout << "arr2 Capacity = " << arr2.getCapacity() << endl;
    cout << "arr2 Size = " << arr2.getSize() << endl;
    
    for(int i = 0 ; i < arr2.getSize() ;++ i)
    {
        cout << arr2[i] << endl;
    }
}
//Person 类连等赋值

void test04()
{
    MyArray<Person> arr(10);
    cout << "请输入要添加元素的个数 : " ;
    int num;
    cin >> num;
    int number;
    string name;
    int age;
    Person p;
    for(int i = 0 ; i < num ; ++ i)
    {
        cout << "请输入第 " << i + 1 << "个姓名 ：" ;
        cin >> name;
        cout << "请输入第 " << i + 1 << "个年龄 ：" ;
        cin >> age;
        p.name = name;
        p.age = age;
        arr.Push(p);
    }
    cout << "arr Capacity = " << arr.getCapacity() << endl;
    cout << "arr Size = " << arr.getSize() << endl;
    
    printPerson(arr);
    MyArray<Person> arr1(10);
    MyArray<Person> arr2(10);
    arr2 = arr1 = arr;
    arr2.Pop();
    arr2.Pop();
    cout << "arr2 Capacity = " << arr2.getCapacity() << endl;
    cout << "arr2 Size = " << arr2.getSize() << endl;
    printPerson(arr2);

}
int main(void)
{
    test04();
}