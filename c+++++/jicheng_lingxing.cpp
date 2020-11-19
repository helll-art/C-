#include<iostream>
#include<string>
using namespace std;

class dongwu
{
    public : 
        int D_age;
};

class yang :  virtual  public dongwu{};
class tuo : virtual public dongwu{};
class yangtuo : public yang ,public tuo{};  


/* void test01()
{
    yangtuo yt;
    yang y;
    y.D_age = 20;
    yt.yang::D_age = 100;
    yt.tuo::D_age = 200;
    cout << yt.yang :: D_age << endl;
    cout << yt.tuo :: D_age << endl;
    cout << yt.D_age << endl;
}
 */

void test02()
{
    yangtuo yt;
    yang y;
    tuo t;
    cout << "\t\tsizeof(yangtuo) = " << sizeof(yt) << endl;
    cout << "\t\tsizeof(yang) = " << sizeof(y) << endl;
    cout << "\t\tsizeof(tuo) = " << sizeof(t) << endl;

}
int main(void)
{
    test02();
}
