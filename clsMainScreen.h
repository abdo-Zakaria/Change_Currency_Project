#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsShowList.h"
#include"clsFindCurr.h"
#include"clsValidate.h"
#include"clsUpdateRate.h"
#include"clsCalcCurr.h"
#include<vector>
class clsMainScreen
{
private:
    enum clsCurrencyOptions  {showList=1,Find=2,Update=3,calcCurr=4,logOut=5};
    static void performMainMenueScreen(clsCurrencyOptions choice)
    {
        switch (choice)
        {
        case  clsCurrencyOptions::showList : 
        clsShowList::ShowList();
            break;
        case  clsCurrencyOptions::Find : 
            clsFind::FindCurr(clsInputValidate::readStirng("Insert code"));
            break;
            case  clsCurrencyOptions::Update : 
            clsUpdateRate::UpdateRate(clsInputValidate::readStirng("Insert code"));
            break;
        case  clsCurrencyOptions::calcCurr : 
        clsCalcCurr::CalcCur();
            break;
        case  clsCurrencyOptions::logOut : 
            break;
        default:
            break;
        }
    }
    /* data */
public:
    static void _ShowMainMenue()
    {
        char desire;
        do
        {
            cout <<"           ====================================================================\n";
            cout <<"                                       Main Menue                             \n";
            cout <<"           ====================================================================\n";
            cout <<"           [1] Show Cuurencies Screen \n";
            cout <<"           [2] Find Cuurency  \n";
            cout <<"           [3] Update  Rate \n";
            cout <<"           [4] Calculate Currency   \n";
            cout <<"           [5] Log Out   \n"; 
            cout <<"           ====================================================================\n";
            cout <<"           choose the option you want : [1-5]   \n           ";
            performMainMenueScreen((clsCurrencyOptions)(clsInputValidate::ReadIntNumberBetween(1,8)));
            cout << "          Do you want to continue  ?  \n           ";
                cin >> desire;
        }while(tolower(desire) == 'y');
    }
};

