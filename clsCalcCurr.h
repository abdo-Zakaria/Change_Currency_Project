#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsValidate.h"
class clsCalcCurr
{

public:
    static void CalcCur()
    {
        string u1 = clsInputValidate::readStirng("insert Currency 1");
        string u2 = clsInputValidate::readStirng("insert Currency 2");
        clsCurrency User1 = clsCurrency::Find(u1);
        clsCurrency User2 = clsCurrency::Find(u2);
        double amount  = clsInputValidate::ReadDblNumber("Amount to Exchange ");
        clsCurrency USA = clsCurrency::Find("USD");
        float Exchange = amount*(User2.Get_amouny_Realtive_to_Dollar() * USA.Get_amouny_Realtive_to_Dollar()) / User1.Get_amouny_Realtive_to_Dollar();
        cout <<amount<<" "<< u1 <<" = "<<Exchange<<" "<<u2<<endl;
    } 
};