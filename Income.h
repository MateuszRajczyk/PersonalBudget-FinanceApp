#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    string date;
    string item;
    string amount;
public:
    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int loadIncomeId();
    int loadUserId();
    string loadDate();
    string loadItem();
    string loadAmount();

};

#endif
