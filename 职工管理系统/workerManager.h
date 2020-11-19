#pragma once  //防止头文件重复包含
#include<iostream> // 包含输入输出流头文件
#include<unistd.h>
#include<fstream>
#include "worker.h" 
#include "boss.h"
#include "employee.h"
#include "manager.h"
using namespace std; //使用标准命名空间

#define FILENAME "empFile.txt"
class WorkerManager
{
    public :

    //记录员工数
    int m_EmpNum;
    //二级指针维护创建的数组
    Worker ** m_EmpArray;
    //判断文件是否为空
    bool m_FileIsEmpty = false;
    WorkerManager();
    void Add_Emp();
    //菜单
    void Show_Menu();
    //退出
    void Exit_System();
    //保存数据到文件
    void save();

    //得到员工数量
    int get_EmpNum();

    //读取职工信息到指针
    void Init_Emp();

    //显示职工信息
    void Display();

    //删除职工时，判断职工是否存在
    int IsExist(string name);
    //删除离职职工
    void Del_Emp();


    //修改职工信息
    void Change_Emp();

    //查找职工信息
    void Find_Emp();

    //对职工编号进行排序
    void Sort();

    //清空文档
    void Truc_File();
    ~WorkerManager();
};

