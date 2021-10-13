#include "Income.h"


void Income::setDateConvertionForSort(int newDateConvertionForSort)
{
    dateConvertionForSort = newDateConvertionForSort;
}
void Income::setIncomeId(int newIncomeId)
{
    if(newIncomeId >= 0)
        incomeId = newIncomeId;
}
void Income::setUserId(int newUserId)
{
    userId = newUserId;
}
void Income::setDate(string newDate)
{
    date = newDate;
}
void Income::setItem(string newItem)
{
    item = newItem;
}
void Income::setAmount(string newAmount)
{
    amount = newAmount;
}

int Income::loadDateConvertionForSort()
{
    return dateConvertionForSort;
}

int Income::loadIncomeId()
{
    return incomeId;
}
int Income::loadUserId()
{
    return userId;
}
string Income::loadDate()
{
    return date;
}
string Income::loadItem()
{
    return item;
}
string Income::loadAmount()
{
    return amount;
}
