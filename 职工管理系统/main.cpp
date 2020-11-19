#include<iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

void test()
{
    Worker * worker = NULL;
    worker = new Employee(1,"张三", 1);
    worker -> showInfo();
    delete worker;

    worker = new Manager(2,"李四" ,2);
    worker -> showInfo();
    delete worker;
    
    worker = new Boss(3,"王五",3);
    worker -> showInfo();
    delete worker;
}
int main(void)
{
    WorkerManager wm;
    int choose = 0;
    while(true)
    {
        wm.Show_Menu();
        cout << "请输入你的选择：" ;
        cin >> choose;
        switch(choose)
        {
            case 0 :
                wm.Exit_System();
                break;
            case 1 :
                wm.Add_Emp();
                break;
            case 2 :
                wm.Display();
                break;
            case 3 :
                wm.Del_Emp();
                break;
            case 4 :
                wm.Change_Emp();
                break;
            case 5 :
                wm.Find_Emp();
                break;
            case 6 :
                wm.Sort();
                break;
            case 7 : 
                wm.Truc_File();
                break;
            default :
                cout << "输入选项错误，请重新输入..." << endl;
                break;
        }
    }
}

