#pragma once
#include<iostream>
#include"clsCurrency.h"
class clsFind
{

public:
    static clsCurrency FindCurr(string code)
    {
        clsCurrency ali = clsCurrency::Find(code);
        ali.Print();
        return ali;
    } 
};