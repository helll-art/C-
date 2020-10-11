#include<iostream>
#include<string>
using namespace std;
#define MAX_SIZE 1000
struct Person
{
    string name;
    string sex;
    int age;
    string phone;
    string address;
};
struct AddressBooks
{
    struct Person person[MAX_SIZE];
    int length;
};
