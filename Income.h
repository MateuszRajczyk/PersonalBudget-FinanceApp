#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    int dateConvertionForSort;
    string date;
    string item;
    string amount;
public:
    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);
    void setDateConvertionForSort(int newDateConvertionForSort);

    int loadIncomeId();
    int loadUserId();
    string loadDate();
    string loadItem();
    string loadAmount();
    int loadDateConvertionForSort();

};

#endif
