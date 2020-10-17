#include<iostream>
using namespace std;
/*
访问权限：
    公共权限：  public       成员 类内可以访问，类外也可以访问   公共厕所
    保护权限：  protected    成员 类内可以访问，类外不可以访问   儿子可以访问父亲的保护内容
    私有权限：  private      成员 类内可以访问，类外不可以访问   儿子不可以访问父亲的私有内容

    class   的默认权限是私有
    struct  的默认权限是公共

*/
class Cube
{
    
public:
    int m_long;
    int m_w;
    int m_high;

    void setSize(void)
    {
        cout << "请分别输入长方体的长宽高：";
        cin >> m_long >> m_w >> m_high;

    }

    int compare(Cube c1,Cube c2)
    {
        if(c1.m_long == c2.m_long && c1.m_w == c2.m_w && c1.m_high == c2.m_high)
            return 1;
        else 
            return -1;
    }
};
/*全局函数 
    可以将这个函数改成引用，这样就不用去拷贝出一份新的对象，节省内存
    还有对于类中成员属性的获取，应该设置为私有属性， 只有需要使用的时候再拿出来
int G_compare(Cube c1,Cube c2)
{
     if(c1.m_long == c2.m_long && c1.m_w == c2.m_w && c1.m_high == c2.m_high)
        return 1;
    else 
        return -1;
}

int main(void)
{
    Cube c1,c2;
    c1.setSize();
    c2.setSize();
    if(1==c1.compare(c1,c2))
        cout << "两个立方体大小一样" << endl;
    else 
        cout << "两个立方体大小不一样" << endl;
    
    if(1 == G_compare(c1,c2))
        cout << "两个立方体大小一样" << endl;
    else 
        cout << "两个立方体大小不一样" << endl;

}