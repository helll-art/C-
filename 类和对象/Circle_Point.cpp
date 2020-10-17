#include<iostream>
using namespace std;


class Circle
{
public:
    double m_r;
    double X_yuanxin,Y_yuanxin;
    double X_point,Y_point;

    int guanxi(void )
    {
        if((X_yuanxin - X_point) * (X_yuanxin - X_point ) + (Y_yuanxin - Y_point) * (Y_yuanxin - Y_point) < m_r * m_r)
            cout << "点在圆内" << endl;
        else if((X_yuanxin - X_point) * (X_yuanxin - X_point ) + (Y_yuanxin - Y_point) * (Y_yuanxin - Y_point) == m_r * m_r)
            cout << "点在圆上" << endl;
        else 
            cout << "点在圆外" << endl;
        return 1;
    }

    void setCircle(void)
    {
        cout << "请输入圆的坐标和半径：" << endl;
        cin >> X_yuanxin >> Y_yuanxin >> m_r;
    }
    void setPoint(void)
    {
        cout << "请输入点的坐标：" << endl;
        cin >> X_point >> Y_point ;
    }

};
int main(void)
{
    Circle c1;
    c1.setPoint();
    c1.setCircle();
    c1.guanxi();
}























