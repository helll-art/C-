#include "manager.h"

Manager :: Manager(int mid,string name,int did)
{
    Mid = mid;
    Name = name;
    Did = did;
};

void Manager :: showInfo()
{
    cout << " " << Mid
        << "\t\t" << Name
        << "\t\t" << this -> getDeptName()
        << "\t\t" << "完成老板的任务，并下发任务给员工" << endl;
}

string Manager :: getDeptName()
{
    return "经理" ;
}
 