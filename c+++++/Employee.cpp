#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>
#include<vector>
using namespace std;

void Add_People();

void Exit(void);
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
        Staff(int No,string name,int station)
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
        Manager(int No,string name,int station)
        {
            this -> No = No;
            this -> name = name;
            this -> station = station;
        }
        void task(void)
        {
            cout << "完成老板交给的任务，并下发给员工" << endl;
        }
} ;

class Boss : public Abstract
{
    public :
        Boss(int No,string name,int station)
        {
            this -> No = No;
            this -> name = name;
            this -> station = station;
        }
        void task(void)
        {
            cout << "管理公司所有事务" << endl;
        }
};
void Use_UI(void);
int main(void)
{
    system("clear");
    int choose;
    Use_UI();
    while(cin >> choose)
    {
        switch(choose)
        {
            case 0 :
                Exit();
                break;

            case 1 :
                Add_People();
                break;

            case 2 :
                break;
            case 3 :
                break;
            case 4 : 
                break;
            case 5 :
                break;
            case 6 :
                break;
            case 7 :
                break;
            default :
                cout << "选项输入错误，请重新输入..." << endl;        
                break;
        }
        system("clear");
        Use_UI();
        
    }
}


void Use_UI(void)
{
    cout << "+------------------------------------------------+" << endl;
    cout << "|                欢迎使用职工管理系统            |" << endl;
    cout << "|                   0.退出管理程序               |" << endl;
    cout << "|                   1.增加职工信息               |" << endl;
    cout << "|                   2.显示职工信息               |" << endl;
    cout << "|                   3.删除离职职工               |" << endl;
    cout << "|                   4.修改职工信息               |" << endl;
    cout << "|                   5.查找职工信息               |" << endl;
    cout << "|                   6.按照编号排序               |" << endl;
    cout << "|                   7.清空所有文档               |" << endl;
    cout << "+------------------------------------------------+" << endl; 
}
void Add_People()
{
    int sum;
    int No;
    string name;
    int  station;
    ofstream ofs;
    ofs.open("./message.txt",ios :: out);
    if(!ofs.is_open())
    {
        cout << "文件打开失败，请重新输入选项" << endl;
        return ;
    }
    cout << "请输入要添加的员工个数" << endl;
    cin >> sum;
    Abstract *Abs;
    for(int i = 1 ; i <= sum ; ++i )
    {
        cout << "请输入第" << i << "个员工的编号";
        cin >> No;
        cout << "请输入第" << i << "个员工的姓名";
        cin >> name;
        cout << "请输入第" << i << "个员工的岗位";
        cin >> station;
        Abs = nullptr;
        if(station == 1)
        {
            Abs = new Boss(No,name,station);
            Abs -> task();
        }
        else if(station == 2)
        {
            Abs = new Manager(No,name,station);
            Abs -> task();
        }
        else if(station == 3)
        {
            Abs = new Staff(No,name,station);
            Abs -> task();
        }
        cout << sizeof(*Abs) << endl;
       
        
        ofs << Abs -> No << " " << Abs -> name << " " <<  Abs -> station << endl;
        delete Abs;
    }
    ofs.close();
    cout << "成功添加 " << sum << "个员工信息" << endl;
    cout << "输入任意键继续" << endl;
    char ch;
    cin >> ch;
}

void Exit(void)
{
    cout << "欢迎下次使用，Bye！" << endl;
    sleep(1);
    
    exit(0);
}

void Display(void)
{
    istream ifs;
    

}