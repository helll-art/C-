#pragma once
#include<iostream>
#include "worker.h"

class Boss : public Worker
{
    public :
        Boss(int mid,string name,int did);
        virtual void showInfo();
        virtual string getDeptName();
};