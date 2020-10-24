#include<stdio.h>


int doWork()
{
    int a = 200;
    printf("%x\n",&a);
    return a;
}
int main(void)
{
    int a = doWork();
    printf("%x\n",&a);
}