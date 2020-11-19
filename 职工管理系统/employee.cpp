#include "employee.h"

Employee :: Employee(int mid,string name,int did)
{
    Mid = mid;
    Name = name;
    Did = did;
}
void Employee :: showInfo()
{
    cout << " " << Mid
        << "\t\t" << Name
        << "\t\t" << this -> getDeptName()
        << "\t\t" << "完成经理交给的任务 " << endl;
}

string Employee :: getDeptName()
{
    //return "员工";
    return string ("员工") ;
}