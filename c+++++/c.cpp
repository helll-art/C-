#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>
#include<vector>
using namespace std;


class Abstract
{
    public :
        int No;
        string name;
        int station;
    virtual void task(void) = 0;
};

class Staff : public Abstract
{
    public :
        Staff(int No,string name ,int station)
        {
            this -> No = No;
            this -> name = name;
            this -> station = station;
        }
        void task(void)    
        {
            cout << "完成经理交给的任务" << endl;
        }
};
class Manager : public Abstract
{
    public :
        void task(void)
        {
            cout << "完成老板交给的任务，并下发给员工" << endl;
        }
} ;

class Boss : public Abstract
{
    public :
        void task(void)
        {
            cout << "管理公司所有事务" << endl;
        }
};

int main(void)
{
    Abstract  * Abs;
    Abs = new Staff(1,"hangsan",1);
    Abs -> task();
}