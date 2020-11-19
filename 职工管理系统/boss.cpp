#include "boss.h"

Boss :: Boss(int mid,string name,int did)
{
    Mid = mid;
    Name = name;
    Did = did;
}

void Boss :: showInfo()
{
    cout << " " << Mid
        << "\t\t" << Name
        << "\t\t" << this -> getDeptName()
        << "\t\t" << "管理公司所有事务 " << endl;
}

string Boss :: getDeptName()
{
    return "总裁";
}