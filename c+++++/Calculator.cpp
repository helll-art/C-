#include<iostream>
#include<string>
using namespace std;
//普通写法
class Calculator
{
    public :
        int Number1;
        int Number2;
    
    int getResult(char oper)
    {
        switch(oper)
        {
            case '+' :
                return Number1 + Number2;
            case '-' :
                return Number1 - Number2;
            case '*' :
                return Number1 * Number2;
            case '/' :
                return Number1 / Number2;
            default :
                cout << "输入错误" << endl;
                return 0;
        }
    }
};

//多态写法
class Abstruct 
{
    public:
        int Number1;
        int Number2;
        virtual int getResult()
        {
            return 0;
        }
};
class AddCalculator : public Abstruct 
{
    public:
        int getResult()
        {
            return Number1 + Number2;
        }
};

class SubCalculator : public Abstruct
{
    public :
        int getResult()
        {
            return Number1 - Number2;
        }
};

class MulCalculator : public Abstruct
{
    public:
        int getResult()
        {
            return Number1 * Number2;
        }
};


void test01()
{
    Calculator C;
    char ch;
    cin >> C.Number1 >> ch >> C.Number2 ;
    cout << C.Number1 << " " << ch << " " << C.Number2 << " = " 
        << C.getResult(ch) << endl;
}

/*
    多态的好处：
    1.组织结构清晰
    2.可读性强
    3.对于前期和后期拓展以及维护性高


    如果想扩展新的功能，需要修改远吗
    在真的开发中提倡开闭原则
    开闭原则：对扩展进行开放，对修改进行关闭
 */
void test02()
{
    char ch;
    Abstruct * Abs;
    cin >> ch ;
    if(ch == '+')
    {
        Abs = new AddCalculator;
        cin >> Abs->Number1 >> Abs -> Number2;
        cout << Abs -> getResult() << endl;
        delete Abs;
    } 
    if(ch == '-')
    {
        Abs = new SubCalculator;
        cin >> Abs->Number1 >> Abs -> Number2;
        cout << Abs -> getResult() << endl;
        delete Abs;
    } 
    if(ch == '*')
    {
        Abs = new MulCalculator;
        cin >> Abs->Number1 >> Abs -> Number2;
        cout << Abs -> getResult() << endl ;
        delete Abs;
    } 
    
}
int main(void)
{
    test02();
}
