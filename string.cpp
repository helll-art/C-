#include<string>
#include<vector>
#include<iostream>
using namespace std;
/*
cin 读取遇到空格停止
getline(cin,string )  读取到换行符才停止
触发getline函数返回的那个换行符实际上被丢弃掉了，得到的string对象中并不包含该换行符
字符串无法对字面值进行相加，

*/
int main()
{
    string s;
    /*
    while(getline(cin,s))
    {
        if(s.size() != 0)
            cout << s << endl;
    }
     
    string k = "abc";
    s = k + "hello " + "world";
    cout << s << endl;
    
   
   每行输出一个字符
   string k = "abc";
   for(auto c : k) （declaration：expression）
        cout << c << endl;
        k 部分是一个对象，用于表示一个序列，declaration部分负责定义一个变量，该变量将被用于访问序列中的基础元素，
        每次迭代，declaration部分的变量会被初始化为expression部分的下一个元素值
    转化为大写形式
    string s("hello world");
    for(auto &c : s )
        c = toupper(c);
    cout << s << endl;
    

    容器
    vector<string> v7(10);
    v7[0] = "a";
    v7[1] = "b";
    cout << v7[0] << "******" << v7[1] << endl;
    
   vector<int> v ;
   for(int i = 0 ;i < 100;i++)
   {
       v.push_back(i);
   }
   for(auto i : v)
    cout << i << "\t" ;

    */
   string ss("some string");
   if(ss.begin() != ss.end())
   {
       /*auto it = ss.begin();
       *it = toupper(*it);
        */
        char &it = ss.begin();
        it = toupper(it);
        
   }
   cout << ss << endl;
}