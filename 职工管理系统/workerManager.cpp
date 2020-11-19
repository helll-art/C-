#include "workerManager.h"


WorkerManager :: WorkerManager()
{
    ifstream ifs;

    
    ifs.open(FILENAME,ios :: in);
    //文件未创建
    if(!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this -> m_EmpNum = 0;
        this -> m_EmpArray = NULL;
        this -> m_FileIsEmpty = true;
        ifs.close();
        return ;

    }
    //文件存在，并且没有记录
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "文件为空！" << endl;
        this -> m_EmpNum = 0;
        this -> m_FileIsEmpty = true;
        this -> m_EmpArray = NULL;
        ifs.close();
        return ;
    }
    int num = this -> get_EmpNum();
    cout << "职工个数为 ： " << num << endl;
    this -> m_EmpNum = num;
    this -> Init_Emp();

    
}
WorkerManager :: ~WorkerManager()
{
    if(this -> m_EmpArray != NULL)
    {
        delete[] this -> m_EmpArray;
        this -> m_EmpArray = NULL;
    }
}

void WorkerManager :: Add_Emp()
{
    cout << "请输入增加员工的数量:";
    int addNum = 0;
    cin >> addNum;

    if(addNum > 0)
    {
        int newSize = this -> m_EmpNum + addNum;
        Worker ** newSpace = new Worker *[newSize];

        if(this -> m_EmpArray != NULL)
        {
            for(int i = 0; i < this -> m_EmpNum ; ++ i)
            {
                newSpace[i] = this -> m_EmpArray[i];
            }
        }
        int k = addNum;
        for(int i = 0 ; i < addNum ; ++ i)
        {
            int id ;
            string name;
            int did;
            cout << "请输入第 " << i + 1 << " 个新员工编号 : " << endl;
            cin >> id;
            cout << "请输入第 " << i + 1 << " 个新员工姓名 ：" << endl;
            cin >> name;
            cout << "请输入第 " << i + 1 << " 个新员工职位 ：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> did;
            Worker * worker = NULL;
            switch(did)
            {
                case 1 :
                    worker = new Employee(id,name,1);
                    break;
                case 2 :
                    worker = new Manager(id,name,2);
                    break;
                case 3 :
                    worker = new Boss(id,name,3);
                    break;
                default : 
                    cout << "输入职工类有误" << endl;
                    k -- ;
                    continue;
                    break;
            }
            newSpace[this -> m_EmpNum + i] = worker;
        } 
        delete[] this -> m_EmpArray;
        this -> m_EmpArray = newSpace;
        this -> m_EmpNum = newSize;

        cout << "成功添加 " << k << " 名新职工！" << endl;
        this -> save();


    }
    else 
    {
        cout << "输入有误" << endl;
    }
}
void WorkerManager ::  Show_Menu()
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
void WorkerManager :: Exit_System()
{
    cout << "欢迎下次使用,Bye~" << endl;
    sleep(1);
    exit(0);
}

void WorkerManager :: save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios :: out);
    if(!ofs.is_open())
    {
        cout << "打开失败" << endl;

    }
    
    for(int i = 0 ; i < this -> m_EmpNum ; ++ i)
    {
        ofs << this -> m_EmpArray[i] -> Mid << " "
            << this -> m_EmpArray[i] -> Name << " "
            << this -> m_EmpArray[i] -> Did << endl;
    }
    ofs.close();
}

void WorkerManager :: Truc_File()
{
    ofstream ofs;
    //如果存在删除文件并重新创建
    ofs.open(FILENAME , ios :: trunc);
    ofs.close();
    delete[] m_EmpArray;
    this -> m_EmpNum = 0;
    m_EmpArray = NULL;
}
void WorkerManager :: Del_Emp()
{
    if(this -> m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        exit(0);
    } 
    string name;
    cout << "请输入要删除的员工姓名 : " ;
    cin >> name;
    int index_name = IsExist(name);
    if(index_name != -1)
    {
        char choose;

        cout << "职工编号" << "\t姓名" << "\t\t职位" << "\t\t职责" << endl;
        this -> m_EmpArray[index_name] -> showInfo();
        cout << "是否进行删除(y or n) : ";
        cin >> choose;
        if(choose == 'Y' || choose == 'y')
        {
                //更新指针数组
            int index = 0;
            int newSize = m_EmpNum - 1;
            Worker ** newSpace = new Worker * [newSize];
            for(int i = 0 ; i < m_EmpNum ; ++ i)
            {
                if(m_EmpArray[i] -> Name == name)
                    continue;
                newSpace[index] = m_EmpArray[i];
                index ++;
            }
            delete[] m_EmpArray;
            m_EmpArray = newSpace;
            m_EmpNum --;
        
            //删除文件中的职工信息
            this -> save();
        }
        else
        {
            cout << "请重新选择" << endl;
        }
        
        

    }
    else
    {
        cout << "输入的姓名有误，请重新进行选择" << endl;
    }
    
}
void WorkerManager :: Display()
{
    /* cout << "职工总人数为 : " << m_EmpNum << endl;
    cout << "职工编号" << "\t姓名" << "\t\t职位" << endl;
    for(int i = 0 ; i < m_EmpNum ; ++ i)
    {
        cout << " " << this -> m_EmpArray[i] -> Mid 
            << "\t\t" << this -> m_EmpArray[i] -> Name
            << "\t\t" << this -> m_EmpArray[i] -> getDeptName() << endl; 
    } */

    if(this -> m_FileIsEmpty)
        cout << "文件不存在或记录为空！" << endl;
    else 
    {
        cout << "职工总人数为 : " << m_EmpNum << endl;
        cout << "职工编号" << "\t姓名" << "\t\t职位" << "\t\t职责" << endl;
        for(int i = 0;i < m_EmpNum ; ++ i)
        {
            this -> m_EmpArray[i] -> showInfo();
        }
    }
}

void WorkerManager :: Init_Emp()
{
    ifstream ifs;
    this -> m_EmpArray = new Worker *[this -> m_EmpNum];
    ifs.open(FILENAME, ios :: in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败,请重新进入程序" << endl;
        
        exit(0) ;
    }
    int did;
    int mid;
    string name;
    int index = 0;
    cout << "......." << endl;
    while(ifs >> mid && ifs >> name && ifs >> did)
    {
        Worker * worker = NULL;
        switch(did)
        {
            case 1 :
                worker = new Employee(mid,name,did);
                break;
            case 2 :
                worker = new Manager(mid,name,did);
                break;
            case 3 :
                worker = new Boss(mid,name,did);
                break;
        }
        this -> m_EmpArray[index] = worker;
        
        index ++;
    }
}
int WorkerManager :: get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME,ios :: in);
    int id;
    string name;
    int did;
    int num = 0;
    while(ifs >> id && ifs >> name && ifs >> did)
    {
        num ++;
    }
    ifs.close();
    return num;
}


void WorkerManager :: Sort()
{
    if(this -> m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        return;
    } 
    cout << "请输入排序方式： " << endl;
    cout << "1.正序  2.逆序 " << endl;
    int choose ;
    cin >> choose;
    
    Worker ** Sort = m_EmpArray;
    Worker * temp = NULL;
    if(choose == 1)
    {
        
        for(int i = 0; i < m_EmpNum ; ++ i)
        {
            for(int j = i + 1 ; j < m_EmpNum ; ++ j)
            {
                if(Sort[i] -> Mid > Sort[j] -> Mid)
                {
                    temp = Sort[i];
                    Sort[i] = Sort[j];
                    Sort[j] = temp;
                }
            }
        }
        
        
    }
    else 
    {
        for(int i = 0 ; i < m_EmpNum ; ++ i)
        {
            for(int j = i + 1 ; j < m_EmpNum ; ++ j)
            {
                if(Sort[i] -> Mid < Sort[j] -> Mid)
                {
                    temp = Sort[i];
                    Sort[i] = Sort[j];
                    Sort[j] = temp;
                }
            }
        }
    }
    cout << "职工编号" << "\t姓名" << "\t\t职位" << "\t\t职责" << endl;
    for(int i = 0 ; i < m_EmpNum ; ++ i)
    {
        Sort[i] -> showInfo();
    }
}
void WorkerManager :: Find_Emp()
{
    if(this -> m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        return;
    } 
    cout << "请输入要查找的职工姓名 ：" ;
    string name;
    cin >> name;
    int index = IsExist(name);
    if(index != -1)
    {
        cout << "职工编号" << "\t姓名" << "\t\t职位" << "\t\t职责" << endl;
        this -> m_EmpArray[index] -> showInfo();
    }
    else 
    {
        cout << "该职工姓名不存在，请重新输入" << endl;
    }

}
void WorkerManager ::  Change_Emp()
{
    string name;
    cout << "请输入要修改的职工姓名 : " << endl;
    cin >> name;
    int index = IsExist(name);
    if(index != -1)
    {
        cout << "职工编号" << "\t姓名" << "\t\t职位" << "\t\t职责" << endl;
        this -> m_EmpArray[index] -> showInfo();
        cout << "是否进行修改(y or n)";
        char choose;
        cin >> choose;
        if(choose == 'Y' || choose == 'y')
        {
            cout << "请输入要修改的选项 (可组合选项) : " << endl;
            cout << "1.修改编号   2.修改姓名  3.修改职位" << endl;
            int ch;
            int did;
            cin >> ch;
            switch(ch)
            {
                case 1 :
                    cout << "请输入该职工编号 : " ;
                    cin >> this -> m_EmpArray[index] -> Mid;
                    break;
                case 2 :
                    cout << "请输入该职工姓名 ：";
                    cin >> this -> m_EmpArray[index] -> Name;
                    break;
                case 3 :
                    cout << "请输入该员工职位 : ";
                    cin >> this -> m_EmpArray[index] -> Did;
                    break;
                case 12 :
                    cout << "请输入该职工编号 : " ;
                    cin >> this -> m_EmpArray[index] -> Mid;
                    cout << "请输入该职工姓名 ：";
                    cin >> this -> m_EmpArray[index] -> Name;
                    break;
                case 13 :
                    cout << "请输入该职工编号 : " ;
                    cin >> this -> m_EmpArray[index] -> Mid;
                    cout << "请输入该员工职位 : ";
                    cin >> this -> m_EmpArray[index] -> Did;
                    break;
                case 23 :
                    cout << "请输入该职工姓名 ：";
                    cin >> this -> m_EmpArray[index] -> Name;
                    cout << "请输入该员工职位 : ";
                    cin >> this -> m_EmpArray[index] -> Did;
                    break;
                case 21 :
                    cout << "请输入该职工编号 : " ;
                    cin >> this -> m_EmpArray[index] -> Mid;
                    cout << "请输入该职工姓名 ：";
                    cin >> this -> m_EmpArray[index] -> Name;
                    break;
                case 31 :
                    cout << "请输入该职工编号 : " ;
                    cin >> this -> m_EmpArray[index] -> Mid;
                    cout << "请输入该员工职位 : ";
                    cin >> this -> m_EmpArray[index] -> Did;
                    break;
                case 32 :
                    cout << "请输入该职工姓名 ：";
                    cin >> this -> m_EmpArray[index] -> Name;
                    cout << "请输入该员工职位 : ";
                    cin >> this -> m_EmpArray[index] -> Did;
                    break;
                default :
                    cout << "输入选项错误..." << endl;
                    break;
            }

            this -> save(); 

        }
    }
}
int WorkerManager :: IsExist(string name)
{
    
    for(int i = 0;i <  m_EmpNum ; ++ i)
    {
        if(m_EmpArray[i] -> Name == name)
        {
            return i;
        }
    }
    return -1;
}