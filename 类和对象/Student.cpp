#include<iostream>
using namespace std;

/*
访问权限：
    公共权限：  public       成员 类内可以访问，类外也可以访问   公共厕所
    保护权限：  protected    成员 类内可以访问，类外不可以访问   儿子可以访问父亲的保护内容
    私有权限：  private      成员 类内可以访问，类外不可以访问   儿子不可以访问父亲的私有内容

*/
class Student
{
public:

    string name;
    string xuehao;
    
protected：
    int chinese;
    int english;
    int math;

    //返回总成绩：
    int all_score(void)
    {
        return chinese + english + math;
    }

    //打印学号，姓名，总成绩

    void print_message(void)
    {
        cout << xuehao << "\t\t" << name << "\t\t" ;
        cout << all_score() << endl;


    }

    //输入各项信息
    void scanf_message(void)
    {
        cout << "请输入学号：" ;
        cin >> xuehao ;
        cout << "请输入姓名：" ;
        cin >> name;
        cout << "请输入语文成绩：";
        cin >> chinese;
        cout << "请输入英语成绩：";
        cin >> english;
        cout << "请输入数学成绩：";
        cin >> math;
    }
};
int main(void)
{
    Student st1,st2;
    st1.scanf_message();
    st1.print_message();
}