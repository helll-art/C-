#include<iostream>
using namespace std;

template < typename T>
void Swap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template < typename T>

void Sort(T *arr,int len)
{
    for(int i = 0 ; i < len ; ++ i)
    {
        for(int j = i + 1 ; j < len ; ++ j)
        {
            if(arr[i] < arr[j])
            {
                Swap(arr[i],arr[j]);
            }
        }
    }
}



template <typename T>
void printArr(T arr,int len)
{
    for(int i = 0;i < len ;++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    int arr[100];
    int len = sizeof(arr) / sizeof(int);
   /*  cout << len << endl;
    for(int i = 0 ; i < 10 ;i ++)
    {
        cin >> arr[i];
    }
    Sort(arr,10);
    printArr(arr,10); */
    
    char str[] = "qweasdzxc";
    cin >> str;
    len = sizeof(str) / sizeof(char);
    cout << str << endl;
    Sort(str,len);
    printArr(str,len);
}