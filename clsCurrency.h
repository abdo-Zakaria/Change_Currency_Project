#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"clsString.h"
using namespace std;
class clsCurrency 
{
private : 
string _CountryName;
string _Code;
string _CurrencyName;
float  _amouny_Realtive_to_Dollar;
clsCurrency(string CountryName, string Code, string CurrencyName,float  amouny_Realtive_to_Dollar)
{
_CountryName=CountryName;
_Code=Code;
_CurrencyName=CurrencyName;
_amouny_Realtive_to_Dollar=amouny_Realtive_to_Dollar;
}
    static string convertObjectToLine(clsCurrency ob , string separator="#//#")
    {
        string result = "";
        result += ob.Get_CountryName()+separator;
        result += ob.Get_Code()+separator;
        result += ob.Get_CurrencyName()+separator;
        result += to_string(ob.Get_amouny_Realtive_to_Dollar())+separator;
        return result;
    }
    static clsCurrency convertLineToObject(string line)
    {
        vector<string> Currency = clsString::Split(line,"#//#");
        clsCurrency ob(Currency[0],Currency[1], Currency[2],stof(Currency[3]));
        return ob;
    }
    static vector<clsCurrency> _LoadCurrencyDataFromFile()
    {
        vector<clsCurrency> allCurr;
        clsCurrency curr("","","",0);
        fstream File;
        File.open("CurrencyFile.txt", ios :: in);
        string line;
        while (getline(File,line))
        {
            curr = convertLineToObject(line);
            allCurr.push_back(curr);
        }
        return allCurr;
    }
    static void _SaveCurrencyDataIntoFile(vector<clsCurrency> allCurr)
    {
        fstream File;
        clsCurrency curr("","","",0);
        File.open("CurrencyFile.txt", ios :: out);
        string line;
        for(int i = 0 ; i < allCurr.size();i++)
        {
            if (File.is_open())
            {
                line = convertObjectToLine(allCurr[i]); 
                File << line <<endl;
            }
        }
        File.close();
    }
   
    public:
    void set_CountryName(string CountryName)
    {
        _CountryName=CountryName;
    }
    string Get_CountryName()
    {
       return _CountryName;
    }
    void set_Code(string Code)
    {
        _Code=Code;
    }
    string Get_Code()
    {
        return _Code;
    }
    void set_CurrencyName(string CurrencyName)
    {
        _CurrencyName=CurrencyName;
    }
    string Get_CurrencyName()
    {
        return _CurrencyName;
    }
    void set_amouny_Realtive_to_Dollar(float amouny_Realtive_to_Dollar)
    {
        _amouny_Realtive_to_Dollar=amouny_Realtive_to_Dollar;
    }
    float Get_amouny_Realtive_to_Dollar()
    {
        return _amouny_Realtive_to_Dollar;
    }
    void Print()
    {
        cout<<"Country Name : "<<_CountryName<<endl;
        cout<<"Country Code : "<<_Code<<endl;
        cout<<"currency Name : "<<_CurrencyName<<endl;
        cout<<"currency Amount (Realtive to Dollar) : "<<_amouny_Realtive_to_Dollar<<endl;
    }
 static clsCurrency Find(string Curr_Code)
    {
        vector<clsCurrency> allCurr = _LoadCurrencyDataFromFile();
        clsCurrency ali("","","",0);
        for (int i = 0; i < allCurr.size(); i++)
        {
            if (clsString::UpperAllString(allCurr[i].Get_Code()) == clsString::UpperAllString(Curr_Code))
            {
                ali = allCurr[i];
            }
        }
        return ali;
    }
static vector<clsCurrency> List()
{
    return _LoadCurrencyDataFromFile();
}
static void UpdateRat(clsCurrency& ali ,float nm)
{
    vector<clsCurrency> allCurr = _LoadCurrencyDataFromFile();
                    ali.set_amouny_Realtive_to_Dollar(nm);
    for (int i = 0; i < allCurr.size(); i++)
    {
        if (clsString::UpperAllString(allCurr[i].Get_Code()) == clsString::UpperAllString(ali.Get_Code()))
            {
                allCurr[i] = ali;
            }
    }
    _SaveCurrencyDataIntoFile(allCurr);
}
};