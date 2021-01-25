#include<iostream>
#include<cstring>
using namespace std;


int KMP(char * str,int slen,char * ptr,int plen,int action);
void cal_next(char * str,int * next,int len);
class MyString
{
    friend ostream & operator << (ostream & cout , MyString str);
    private : 
        char * mystring ;
        int size;
    public :
        int getSize();
        

        //构造析构
        MyString();
        
        MyString(const char * s);
        
        MyString(const MyString & str);
        
        MyString(int n,char c);
        
        ~MyString();
        

        //赋值操作

        MyString&  operator = (const MyString & a);
        MyString&  operator = (const char * s);
        MyString&  operator = (char ch);

        MyString& assign(const char * s);
        MyString& assign(const MyString & a);
        MyString& assign(int n,char c);
        MyString& assign(const char * s,int n);

        //查找替换
        int find(const MyString & a,int pos = 0);
        int find(const char c,int pos = 0);
        int rfind(const MyString & a,int pos = 0);
        int rfind(const char c,int pos = 0);
        MyString & replace(int pos,int n,const MyString & str);

        //字符串比较

        int compare(const MyString & s);
        
        //字符串存取

        char  operator[](int n);
        char at(int n);

        //插入删除
        MyString  operator + (MyString & a);
        MyString & insert(int pos,const MyString &a);
        MyString & erase(int pos);

        //获取子串

        MyString substr(int pos ,int npos );

        //判断是否为空串
        bool empty();

        
        
        


};






MyString :: MyString()
{
    mystring = NULL;
}
int MyString ::  getSize()
{
    return this -> size;
}
MyString :: MyString(const char * s)
{
    size = strlen(s);
    mystring = new char[size + 1];
    strcpy(mystring,s);
}
MyString :: MyString(const MyString & str)
{
    this -> size = strlen(str.mystring);
    this -> mystring = new char[size + 1];
    strcpy(this -> mystring , str.mystring);
}
MyString :: MyString(int n,char c)
{

    this -> size = n;
    this -> mystring = new char[size + 1];
    for(int i = 0 ; i < size  ; ++ i)
    {
        mystring[i] = c;    
    }
    mystring[size] = '\0';
}
MyString :: ~MyString()
{
    if(mystring != NULL)
        delete [] mystring;
    
}
ostream & operator << (ostream & cout , MyString str)
{
    cout << str.mystring;
    return cout;
}






//赋值操作

MyString& MyString :: operator = (const MyString & a)
{
    if(this -> mystring != NULL)
        delete [] this -> mystring;

    this -> size = a.size;
    this -> mystring = new char[this -> size];
    strcpy(this -> mystring,a.mystring);
    return *this;
}
MyString& MyString :: operator = (const char * s)
{
    if(this -> mystring != NULL)
        delete [] this -> mystring;
    this -> size = strlen(s);
    this -> mystring = new char[size + 1];
    strcpy(this -> mystring,s);
    return *this;
}

MyString& MyString :: operator = (char ch)
{
    if(this -> mystring != NULL)
        delete [] this -> mystring;
    this -> size = 2;
    this -> mystring = new char[size];
    this -> mystring[0] = ch;
    this -> mystring[1] = '\0';
    return * this;
}

MyString& MyString :: assign(const char * s)
{
    if(this -> mystring != NULL)
        delete [] this -> mystring;
    this -> size = strlen(s);
    this -> mystring = new char[size + 1];
    strcpy(this -> mystring , s);
    this -> mystring[size] = '\0';
}

MyString&  MyString :: assign(const MyString & a)
{
    if(this -> mystring != NULL)
        delete[] this -> mystring;
    this -> size = a.size;
    this -> mystring = new char[size];
    strcpy(this -> mystring,a.mystring);
    return * this;
}

MyString& MyString :: assign(int n,char c)
{
    if(this -> mystring != NULL)
        delete[] this -> mystring;
    this -> size = n;
    this -> mystring = new char[size];
    for(int i = 0 ; i < n ; ++ i)
    {
        this -> mystring[i] = c;
    }
    this -> mystring[size] = '\0';
}

MyString& MyString :: assign(const char * s,int n)
{
    this -> size = n;
    if(this -> mystring != NULL)
        delete [] this -> mystring;
    this -> mystring = new char[size];
    for(int i = 0 ; i < n ; ++ i)
    {
        this -> mystring[i] = s[i];
    }
    this -> mystring[n] = '\0';
}


//查找替换
int MyString :: find(const MyString & a,int pos)
{
    return KMP(this -> mystring,strlen(this -> mystring),a.mystring,strlen(a.mystring),pos);
}
void cal_next(char * str,int * next,int len)
{
    next[0] = -1;
    int k = -1;
    for(int q = 1; q <= len - 1; ++ q)
    {
        while(k > -1 && str[k + 1] != str[q])
            k = next[k];
        if(str[k + 1] == str[q])
            k = k + 1;
        next[q] = k;
    }
}

int KMP(char * str,int slen,char * ptr,int plen,int action)
{

    int * next = new int[plen];
    cal_next(ptr,next,plen);
    int k = -1;
    for(int i = action ; i < slen ; ++ i)
    {
        while(k > -1 && ptr[k + 1] != str[i])
            k = next[k];
        if(ptr[k + 1] == str[i])
            k ++;
        if(k == plen - 1)
        {
            return i - plen + 1;
        }
    }
    return -1;
}
int MyString :: find(const char ch,int pos)
{
    for(int i = 0 ; i < this -> size ; ++ i)
    {
        if(ch == this -> mystring[i])
            return i + 1;
    }
    return -1;
}

int MyString :: rfind(const MyString &a , int pos)
{
    MyString temp;
    temp = * this;
    char temp_ch;
    int i = 0;
    int j = this -> size - 1;
    while( i < j)
    {
        temp_ch = temp.mystring[i];
        temp.mystring[i] = temp.mystring[j];
        temp.mystring[j] = temp_ch;
        i++;
        j--;
    }
    return KMP(temp.mystring,strlen(temp.mystring),a.mystring,strlen(a.mystring),pos);
}
int MyString :: rfind(const char ch , int pos)
{
    MyString temp;
    temp = * this;
    char temp_ch;
    int i = 0;
    int j = this -> size - 1;
    while( i < j)
    {
        temp_ch = temp.mystring[i];
        temp.mystring[i] = temp.mystring[j];
        temp.mystring[j] = temp_ch;
        i++;
        j--;
    }
    for(int i = 0 ; i < this -> size ; ++ i)
    {
        if(temp.mystring[i] == ch)
            return i;
    }
    return -1;
}

MyString & MyString :: replace(int pos,int n,const MyString & str)
{
    MyString temp = * this;
    if(this -> size < pos + n)
        delete[] this -> mystring;
    this -> size = pos + n;
    this -> mystring = new char[size];
    for(int i = 0 ; i < pos ; ++i)
    {
        this -> mystring[i] = temp.mystring[i];
    }
    int k = 0;
    for(int i = pos; i < pos + n; ++ i)
    {

        this -> mystring[i] = str.mystring[k++];
        
    }
    this -> mystring[size] = '\0';
    return * this;
}

//字符串比较


int MyString :: compare(const MyString & s)
{
    return strcmp(this -> mystring,s.mystring);
}



//字符串存取

char MyString ::  operator[](int n)
{
    return this -> mystring[n];
}
char MyString ::  at(int n)
{
    return this -> mystring[n];
}


//插入删除

MyString  MyString :: operator + (MyString & a)
{
    MyString temp;
    temp.size = a.size + this -> size;
    temp.mystring = new char[temp.size];
    int i ;
    for( i = 0 ; i < this -> size ; ++ i)
    {
        temp.mystring[i] = this -> mystring[i];
    }
    for(int j = 0; j < a.size ; ++ j)
    {
        temp.mystring[i++] = a.mystring[j];
    }
    
    temp.mystring[temp.size] = '\0';
    return temp;
}
MyString & MyString :: insert(int pos, const MyString &a)
{
    
    MyString temp = *this;
    if(this -> mystring != NULL)
        delete [] mystring;
    this -> size = temp.size + a.size  ;

    this -> mystring = new char[size + 1];
    
    int i ;
    for(i = 0 ; i < pos ; ++ i)
    {   
        this -> mystring[i] = temp[i];
    }
    cout << *this << endl;
    int flag = i;
    for(int j = 0 ; j < a.size ; ++ j)
    {
        this -> mystring[i++] = a.mystring[j];
    }
    cout << *this << endl;
    
    for(int j = flag ; j < temp.size ; ++ j)
    {
        this -> mystring[i++] = temp.mystring[j];
    }
    this -> mystring[size ] = '\0';
    return *this;
}

MyString & MyString :: erase(int pos)
{
    this -> size = pos;
    this -> mystring[pos] = '\0';
    return * this; 
}

MyString MyString :: substr(int pos ,int npos )
{
    if(npos - pos <= 0)
    {
        cout << "输入错误" << endl;
        exit(1);
    }
    MyString temp;
    int j = 0;
    temp . size = npos - pos;
    temp . mystring = new char[temp.size];
    
    for(int i = pos ; i < npos ; ++ i)
    {
        
        temp.mystring[j++] = this -> mystring[i];
    }
    temp.mystring[j] = '\0';
    return temp;
}

//判断是否为空串

bool MyString :: empty()
{
    if(this -> size == 0)
        return true;
    else 
        return false;
}


void test01()
{
    MyString str(10,'n');
    MyString str1;
    MyString str2;
    str2 =  str1 = str;
    cout << str1.getSize() << endl;
    cout << str1 << endl;
    cout << str2.getSize() << endl;
    cout << str2 << endl;
    str2 = "i lo ve y ou";
    cout << str2.getSize() << endl;
    cout << str2 << endl;
}
void test02()
{
    MyString str ;
    str = 'a';
    cout << str << endl;
    str.assign(10,'h');
    MyString str1;
    str1.assign("hello world",5);
    cout << str1 << endl;
}

void test03()
{
    MyString str;
    str = "abcdefghigl";
    
    MyString a = "hello world";
    
    MyString b = a + str;
    cout << b << endl;
}
int main(int argc, char const *argv[])
{
    test03();
}
