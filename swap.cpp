#include "swap.h"
void swap(int c,int d)
{
    int temp ;
    temp = c;
    c = d;
    d = temp;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}