#pragma once
#include<iostream>
#include"clsCurrency.h"
class clsUpdateRate
{

public:
    static void UpdateRate(string code)
    {
        float nm = 0;
        clsCurrency ali = clsCurrency::Find(code);
        ali.Print();
        cout<<"Enter The New Rate \n";
        cin>>nm;
        clsCurrency::UpdateRat(ali,nm);
        ali.Print();
    } 
};