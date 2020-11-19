#pragma once
#include<iostream>
#include<string>

using namespace std;

class Worker
{
    public :

        //显示个人信息
        virtual void showInfo() = 0;
        //获取岗位名称
        virtual string getDeptName() = 0;

        int Mid; // 编号
        string Name;    //姓名
        int Did;   //职工所在部门编号
};