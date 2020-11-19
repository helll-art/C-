#include<iostream>
using namespace std;
void sortColors(int A[],int n);
int main(void)
{
    int b[10] = {2,2,1,1,1,0,0,0,0};
    sortColors(b,10);
}

void sortColors(int A[],int n)
{
    int blue = 0,red = 0,white = 0;
    for(int i = 0 ; i < n ; ++ i)
    {
        if(A[i] == 0)
            red ++;
        else if(A[i] == 1)
            white ++;
        else if(A[i] == 2)
            blue ++;
    }
    for(int i = 0;i < red ; ++i)
        A[i] = 0;
    for(int i = red ; i < red + white ; ++i)
        A[i] = 1;
    for(int i = red + white ;i < n;++ i)
        A[i] = 2;

    for(int i = 0;i < 10;i++)
    {
        cout << A[i] << endl;
    }
}