#include<iostream>
#include<string>
using namespace std;


//自动类型推导，不会发生隐式类型转换
//显示指定类型，会发生隐式类型转换
//普通函数类型，会进行隐式类型转换
template <typename T>

void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>

void mySort_Down(T arr[],int len)
{
    for(int i = 0 ; i < len ; ++ i)
    {
        //int max = i;
        for(int j = i + 1 ; j < len ; ++ j)
        {
            if(arr[i] > arr[j])
            {
                mySwap(arr[i],arr[j]);
            }
        }
    }
}

template < typename T>

void printArr(T arr[], int  len)
{
    for(int i = 0 ; i < len ; ++ i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    char arr[] = "abcdefgh";
    int len = sizeof(arr - sizeof(char)) / sizeof(char);
    
    mySort_Down(arr,len);
    printArr(arr,len);

    int a[10];
    for(int i = 0 ; i < 10 ; ++ i)
    {
        cin >> a[i];
    }
    int len_a = sizeof(a) / sizeof(int);
    mySort_Down(a,len_a);
    printArr(a,len_a);

}