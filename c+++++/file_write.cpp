#include<iostream>
#include<string>
#include<fstream>
using namespace std;


/*
    ios :: in    为读文件而打开文件
    ios :: out   为写文件而打开文件
    ios :: ate   初始位置：文件尾
    ios :: app   追加方式写文件
    ios :: trunc 如果文件存在先删除，在创建
    ios :: binary二进制方式
    ios :: nocreate 打开一个文件时，如果文件不存在，不创建文件
    ios :: noreplace 打开一个文件时，如果文件不存在，创建该文件
    file.seekg(0,ios::beg);   //让文件指针定位到文件开头 

     file.seekg(0,ios::end);   //让文件指针定位到文件末尾 

     file.seekg(10,ios::cur);   //让文件指针从当前位置向文件末方向移动10个字节 

     file.seekg(-10,ios::cur);   //让文件指针从当前位置向文件开始方向移动10个字节 

     file.seekg(10,ios::beg);   //让文件指针定位到离文件开头10个字节的位置

 */
int main(void)
{
    ofstream ofs;
    ofs.open("../tiaoshi.txt",ios::out);
    ofs << "abcdefg" << endl;
    ofs << "dddddddddd" << endl;
    ofs.close();
}