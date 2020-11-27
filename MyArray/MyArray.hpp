#include<iostream>
#include<string>
using namespace std;

template< class T>
class MyArray
{
    private:
        //容量
        int capacity;
        //大小
        int size;
        //数组指针
        T * pAddress = NULL;

    public :

        MyArray(int capacity);
        //防止浅拷贝问题
        MyArray(const MyArray & p);
        ~MyArray();
        //让多种类型能够进行赋值
        MyArray & operator = (const MyArray & p);
        //尾插法
        void Push(const T & val);
        //尾删法
        void Pop(void);
        //遍历查看所有元素
        void Traverse();
        //查看特定元素
        T Find_Index(int val);

        //通过下标方式访问数组中的元素
        T& operator[] (int index);
        //返回数组大小
        int getSize();
        //返回数组容量
        int getCapacity();
        
};

template <class T>
MyArray<T> :: MyArray(int capacity)
{
    this -> size = 0;
    this -> capacity = capacity;
    this -> pAddress = new T[this -> capacity];

}

template <class T>
MyArray<T> :: MyArray(const MyArray & a)
{
    if(this -> pAddress != NULL)
    {
        delete [] pAddress;
    }
    this -> size = a.size;
    this -> capacity = a.capacity ;
    if(a.pAddress != NULL)
    {
        this -> pAddress = new T[this -> capacity];
    }
    for(int i = 0 ; i < this -> size ; ++ i)
    {
        this -> pAddress[i] = a.pAddress[i];
    }
}

template < class T >
MyArray<T> :: ~MyArray()
{
    if(this -> pAddress != NULL)
    {
        delete [] this -> pAddress;
        this -> pAddress = NULL;
    }
    this -> size = 0;
    this -> capacity = 0;
}

template <class T>
MyArray<T> &  MyArray<T> :: operator = (const MyArray & p)
{
    this -> size = p.size;
    this -> capacity = p.capacity;
    if(this -> pAddress != NULL)
    {
        delete [] pAddress;
        this -> pAddress = NULL;
    }
    this -> pAddress = new T[this -> capacity];
    for(int i = 0 ;i < this -> size ; ++ i)
    {
        this -> pAddress[i] = p.pAddress[i];
    }
    return  *this;
}

template < class T>
int MyArray<T> :: getSize()
{
    return this -> size;
}

template < class T>
int MyArray<T> :: getCapacity()
{
    return this -> capacity ; 
} 

template <class T>
T& MyArray<T> :: operator[](int index)
{
    return this -> pAddress[index];
}

template <class T>
T MyArray<T> :: Find_Index(int index)
{
    return this -> pAdress[index];
}

template <class T>

void MyArray<T> :: Push(const T &a)
{
    if(this -> size - 1 >= this -> capacity)
    {
        cout << "数组已满" << endl;
        return ;
    }
    this -> pAddress[this -> size] = a;
    ++ this -> size ; 
}

template <class T>

void MyArray<T> :: Pop()
{
    if(this -> size < 0)
    {
        cout << "没有元素可以删除" << endl;
        return ;
    }
    
    --this -> size ;
}
