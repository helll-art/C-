
#include "swap.h"

void Show_Book(struct AddressBooks * current );
void Init(struct AddressBooks * current );
int Add_Person(struct AddressBooks *current );
int Delete_Person(struct AddressBooks * current );
int Get_Person(struct AddressBooks * current );
int Update_Person(struct AddressBooks * current );

void Show_Menu(void);
int main(void)
{
    struct AddressBooks book;
    Init(&book);
    int select ;
    while(1)
    {
        Show_Menu();
        cout << "请输入选项：" ;
        cin >> select;
        switch(select)
        {
            case 1:
                if(Add_Person(&book) == 1)
                    cout << "添加成功" << endl;
                break;
            case 2:
                Show_Book(&book);
                break;
            case 3:
                if(Delete_Person(&book) == 1)
                    cout << "删除成功..." << endl;
                break;
            case 4:
                if(Get_Person(&book) == 0)
                    cout << "查无此人..." << endl;
                break;
            case 5:
                Update_Person(&book);
                break;
            case 6:
                Init(&book);
                break;
            case 0:
                cout << "欢迎下次使用！" << endl;
                
                return 0;
                break;
            default :
                cout << "输入选项错误，请重新输入..." << endl;
                break;

        }
    }
}

void Show_Menu(void)
{
    cout << "**********************************" << endl;
    cout << "*******   1.添加联系人 ***********" << endl;
    cout << "*******   2.显示联系人 ***********" << endl;
    cout << "*******   3.删除联系人 ***********" << endl;
    cout << "*******   4.查找联系人 ***********" << endl;
    cout << "*******   5.修改联系人 ***********" << endl;
    cout << "*******   6.清空联系人 ***********" << endl;
    cout << "*******   0.退出通讯录 ***********" << endl;
    cout << "**********************************" << endl;
}
int Add_Person(struct AddressBooks *current )
{
    if(current -> length == MAX_SIZE)
    {
        cout << "联系人以达到上限,无法继续添加" << endl;
        return 0;
    } 
    current -> length ++;
    cout << "请输入要添加联系人的姓名：";
    cin >> current -> person[current -> length].name;
    cout << "性别：";
    cin >> current -> person[current -> length].sex;
    cout << "年龄：";
    cin >> current -> person[current -> length].age;
    cout << "联系电话：";
    cin >> current -> person[current -> length].phone;
    cout << "家庭住址：";
    cin >> current -> person[current -> length].address;
    
    return 1;
}
void Init(struct AddressBooks * current )
{
    current -> length = 0;
}
void Show_Book(struct AddressBooks * current )
{
    cout << "编号\t姓名\t性别\t年龄\t联系电话\t\t家庭住址" << endl;
    for(int i = 1 ;i <= current -> length;i++)
    {
        cout << i << "\t" 
            << current -> person[i].name << "\t"
            << current -> person[i].sex << "\t"
            << current -> person[i].age << "\t"
            << current -> person[i].phone << "\t\t\t"
            << current -> person[i].address << endl;
    }
}

int Delete_Person(struct AddressBooks * current )
{
    string name;
    cout << "请输入要删除联系人的姓名:";
    cin >> name;
    if(current -> length == 0)
    {
        cout << "没有联系人，无法删除" << endl;
        return 0;
    }
    for(int i = 1;i <= current -> length ;i++)
    {
        if(name == current -> person[i].name)
        {
            current -> length --;
            for(int j = i; j <= current -> length ; j++)
            {
                current -> person[j] = current -> person[j + 1];
            }
            return 1;
        }
    }
    return 0;

}
int Get_Person(struct AddressBooks * current )
{
    string name;
    cout << "请输入要查找联系人的姓名:";
    cin >> name;
    for(int i = 1;i <= current -> length ; i++)
    {
        if(name == current -> person[i].name)
        {
            cout << "姓名：" << current ->person[i].name 
                <<"\n性别:" << current -> person[i].sex
                <<"\n年龄：" << current -> person[i].age
                <<"\n联系电话：" << current -> person[i].phone
                <<"\n家庭住址：" << current -> person[i].address << endl;
            return 1;
        }
    }
    return 0;
}
int Update_Person(struct AddressBooks * current )
{
    string name;
    cout << "请输入要修改联系人的姓名：" ;
    cin >> name;
    for(int i = 1;i <= current -> length ; i++)
    {
        if(name == current -> person[i].name)
        {
            cout << "开始修改信息..." << endl;
            cout << "姓名：" ;
            cin >> current -> person[i].name;
            cout << "性别：";
            cin >> current -> person[i].sex;
            cout << "年龄：";
            cin >> current -> person[i].age;
            cout << "联系电话：";
            cin >> current -> person[i].phone;
            cout << "家庭住址：";
            cin >> current -> person[i].address;
            cout << "修改信息成功" << endl;
            return 1;
        }
    }
    cout << "未查找到此人..." << endl;
    return 0;

}