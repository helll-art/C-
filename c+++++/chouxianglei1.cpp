#include<iostream>
#include<string>
using namespace std;

class Abstract_Drinking
{
    public :
        virtual void Boil() = 0;
        virtual void PutSomeing() = 0;
        virtual void Brew() = 0;
        //virtual void PourInCup() = 0;
        void PourInCup()
        {
            cout << "倒入杯中" << endl;
        }
        void DoWork()
        {
            Boil();
            PutSomeing();
            Brew();
            PourInCup();
        }
};

class Coffee : public Abstract_Drinking
{
    public :
        void Boil()
        {
            cout << "煮水 " << endl;
        }
        void PutSomeing()
        {
            cout << "加入枸杞" << endl;
        }
        void Brew()
        {
            cout << "加入咖啡" << endl;
        }
        void PourInCup()
        {
            cout << "倒入杯中"  << endl;
        }
};
class Tea : public Abstract_Drinking
{
    public:
        void Boil()
        {
            cout << "煮水茶" << endl;
        }
        void PutSomeing()
        {
            cout << "加入咖啡和糖" << endl;
        }
        void Brew()
        {
            cout << "加入茶叶" << endl;
        }
};

void doWork(Abstract_Drinking * Abs)
{
    Abs -> Boil();
    Abs -> PutSomeing();
    Abs -> PourInCup();
    Abs -> Brew();
    cout << "------------------" << endl;
    Abs -> DoWork();
    delete Abs;
}

int main(void)
{
    doWork(new Coffee);
    doWork(new Tea);
}
