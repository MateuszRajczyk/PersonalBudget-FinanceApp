#include "Expense.h"

void Expense::setDateConvertionForSort(int newDateConvertionForSort)
{
    dateConvertionForSort = newDateConvertionForSort;
}
void Expense::setExpenseId(int newExpenseId)
{
    if(newExpenseId >= 0)
        expenseId = newExpenseId;
}
void Expense::setUserId(int newUserId)
{
    userId = newUserId;
}
void Expense::setDate(string newDate)
{
    date = newDate;
}
void Expense::setItem(string newItem)
{
    item = newItem;
}
void Expense::setAmount(string newAmount)
{
    amount = newAmount;
}

int Expense::loadDateConvertionForSort()
{
    return dateConvertionForSort;
}

int Expense::loadExpenseId()
{
    return expenseId;
}
int Expense::loadUserId()
{
    return userId;
}
string Expense::loadDate()
{
    return date;
}
string Expense::loadItem()
{
    return item;
}
string Expense::loadAmount()
{
    return amount;
}
