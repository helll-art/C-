#include<iostream>
using namespace std;

class Circle
{
    //权限：
public:

    //属性：
    int m_r;
    const double PI = 3.14159;
    //行为：

    double caclulateZC()
    {
        return 2 * PI * m_r;
    }
};
int main(void)
{
    Circle c1;
    c1.m_r = 5;
    cout << "圆的周长为：" << c1.caclulateZC() << endl;
    
}