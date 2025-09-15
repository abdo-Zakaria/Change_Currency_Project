#pragma once
#include<iostream>
#include"clsCurrency.h"
#include<vector>
#include<iomanip>
class clsShowList
{

public:
    // static void ShowList()
    // {
    //     vector<clsCurrency> allCurr = clsCurrency::List();
    //     cout<<"Country Name               | Country Code | CurrencyName               | Relative To Dollar \n";
    //     for (int i = 0; i < allCurr.size(); i++)
    //     {
    //         cout<<allCurr[i].Get_CountryName()<<"| "<<allCurr[i].Get_Code()<<" | "<<
    //         allCurr[i].Get_CurrencyName()<<"| "<<allCurr[i].Get_amouny_Realtive_to_Dollar()<<"\n";
    //     }
        
    // } 
    static void ShowList() {
        vector<clsCurrency> allCurr = clsCurrency::List();

        // العناوين
        vector<string> headers = {"Country Name", "Country Code", "Currency Name", "Relative To Dollar"};

        // حساب عرض الأعمدة
        vector<size_t> widths(headers.size(), 0);
        for (size_t i = 0; i < headers.size(); i++) {
            widths[i] = headers[i].size();
        }

        for (clsCurrency  &c : allCurr) {
            widths[0] = max(widths[0], c.Get_CountryName().size());
            widths[1] = max(widths[1], c.Get_Code().size());
            widths[2] = max(widths[2], c.Get_CurrencyName().size());
            widths[3] = max(widths[3], to_string(c.Get_amouny_Realtive_to_Dollar()).size());
        }

        // طباعة العناوين
        cout << "\nCurrency List:\n";
        for (size_t i = 0; i < headers.size(); i++) {
            cout << left << setw(widths[i] + 3) << headers[i] << "| ";
        }
        cout << "\n";

        // خط فاصل
        size_t totalWidth = 0;
        for (auto w : widths) totalWidth += w + 3;
        cout << string(totalWidth + headers.size() * 2, '-') << "\n";

        // طباعة البيانات
        for (clsCurrency  &c : allCurr) {
            cout << left << setw(widths[0] + 3) << c.Get_CountryName() << "| ";
            cout << left << setw(widths[1] + 3) << c.Get_Code() << "| ";
            cout << left << setw(widths[2] + 3) << c.Get_CurrencyName() << "| ";
            cout << left << setw(widths[3] + 3) << c.Get_amouny_Realtive_to_Dollar() ;
            cout << "\n";
        }
    }
};
/*    public: 
    static clsBankClient Find(string AccountNumber)
    {
        clsBankClient cleint = clsBankClient::Find(AccountNumber);
        cleint.Print();
        return cleint;
    }*/
