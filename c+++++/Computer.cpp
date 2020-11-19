#include<iostream>
#include<string>

using namespace std;
class CPU
{
    public:
        virtual void calculate() = 0;
};
class VideoCard
{
    public:
        virtual void display() = 0;
};
class Memory
{
    public:
        virtual void storage() = 0;
};

class Intel_CPU : public CPU 
{
    public :
        void calculate()
        {
            cout << "Inter的cpu开始计算了" << endl;
        }
};
class Intel_VideoCard : public VideoCard 
{
    public :
        void display()
        {
            cout << "Inter的显卡开始显示了" << endl;
        }
};
class Intel_Memory : public Memory 
{
    public :
        void storage()
        {
            cout << "Inter的内存开始存储了" << endl;
        }
};
class Leveno_CPU : public CPU 
{
    public :
        void calculate()
        {
            cout << "Leveno的cpu开始计算了" << endl;
        }
};
class Lenevo_VideoCard : public VideoCard 
{
    public :
        void display()
        {
            cout << "Lenevo的显卡开始显示了" << endl;
        }
};
class Lenevo_Memory : public Memory 
{
    public :
        void storage()
        {
            cout << "Lenevo的内存开始存储了" << endl;
        }
};

class Computer
{
    public:
        CPU * cpu;
        Memory * mem;
        VideoCard * vc;
        Computer(CPU * cpu1,Memory * memory,VideoCard *videocard)
        {
            cpu = cpu1;
            mem = memory;
            vc = videocard;
        }
        void doWork()
        {
            cpu -> calculate();
            vc -> display();
            mem -> storage();
        }
};


void test01()
{
    Intel_CPU * cpu = new Intel_CPU;
    Intel_Memory * mem = new Intel_Memory;
    Intel_VideoCard * vc = new Intel_VideoCard;
    Computer first_com(cpu,mem,vc);
    first_com.doWork();
}

void test02()
{
    Intel_CPU * cpu = new Intel_CPU;
    Lenevo_Memory * mem = new Lenevo_Memory;
    Lenevo_VideoCard * vc = new Lenevo_VideoCard;
    Computer China_Com(cpu,mem,vc);
    China_Com.doWork();
}
int main(void)
{
    test01();
    cout << "---------------" << endl;
    test02();
}