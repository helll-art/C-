#include<iostream>
#include<ctime>
using namespace std;

int main(void)
{
    int num ;
    srand((unsigned int ) time(NULL));
    int gress_num;
    num = rand() % 100;
    cout << num << endl;
    
    int i = 0;
    do
    {
        cout << "请重新输入一个数 ：";
        cin >> gress_num;
        if(num > gress_num)
        {
            cout << "猜小了" << endl;
        }
        if(num < gress_num)
        {
            cout << "猜大了" << endl;
        }
        i++;
        
    }while(num != gress_num);
    cout << "猜次猜对了" << i << endl;
    
}