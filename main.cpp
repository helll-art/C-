
#include "swap.h"


int main(void)
{
    srand((unsigned int ) time(NULL)); 
    string ABC = "ABCDE";
   Teacher teacher[3];
   for(int i = 0;i < 3;i++)
   {
       teacher[i].T_name = "Teacher_";
       teacher[i].T_name = teacher[i].T_name + ABC[i];
   }
   for(int i = 0 ; i < 3;i++ )
   {
       
       for(int j = 0;j < 5;j++)
       {
           
           teacher[i].student[j].name = "Student_";
           teacher[i].student[j].name += ABC[j];
           teacher[i].student[j].score = rand() % 60 + 40;
       }
   }

    for(int i = 0 ; i < 3;i++)
    {
        cout << "老师姓名：" << teacher[i].T_name << endl;
        for(int j = 0;j < 5;j++)
        {
            cout << "\t学生姓名:" << teacher[i].student[j].name << "\t学生分数：" << teacher[i].student[j].score << endl;
        }
    }
}