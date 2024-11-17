#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen :protected clsScreen
{

private:
    static void _PrintCurrency(clsCurrency Currency, bool CurrencyCodeOrCountry)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";

        if(CurrencyCodeOrCountry)
        cout << "\nCountry    : " << Currency.Country();

        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";

    }

    static void _ShowResults(clsCurrency Currency, bool CurrencyCodeOrCountry)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency, CurrencyCodeOrCountry);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer;
        Answer = clsInputValidate::ReadShortNumberBetween(1, 2);


        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter CurrencyCode: ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency,false);
        }
        else
        {
            string Country;
            cout << "\nPlease Enter Country Name: ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency,true);
        }


    }

};

