#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    int expenseId;
    int userId;
    int dateConvertionForSort;
    string date;
    string item;
    string amount;
public:
    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);
    void setDateConvertionForSort(int newDateConvertionForSort);

    int loadExpenseId();
    int loadUserId();
    string loadDate();
    string loadItem();
    string loadAmount();
    int loadDateConvertionForSort();

};

#endif
