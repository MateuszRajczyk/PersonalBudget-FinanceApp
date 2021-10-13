#ifndef FINANCEMENAGER_H
#define FINANCEMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "FileWithFinance.h"
#include "Income.h"
#include "Expense.h"
#include "SupplementaryMethods.h"



using namespace std;

class FinanceMenager
{
    const int ID_OF_LOGGED_USER;

    vector<Income>incomes;
    vector<Expense>expenses;

    FileWithFinance fileWithFinance;

    Income enterDataOfNewIncomeWithCurrentDate();
    Income enterDataOfNewIncomeWithSelectedDate();

    Expense enterDataOfNewExpenseWithCurrentDate();
    Expense enterDataOfNewExpenseWithSelectedDate();
public:
    FinanceMenager(string nameFileWithIncomes, string nameFileWithExpenses, int idOfLoggedUser)
        : fileWithFinance(nameFileWithIncomes, nameFileWithExpenses), ID_OF_LOGGED_USER(idOfLoggedUser)
    {
        fileWithFinance.readIdLastExpense();
        fileWithFinance.readIdLastIncome();
        incomes = fileWithFinance.loadIncomesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
        expenses = fileWithFinance.loadExpensesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    };
    void addNewIncome();
    void addIncomeFromCurrentDay();
    void addIncomeWithSelectedDate();
    void addNewExpense();
    char selectOptionsFromAddIncomeMenu();
    bool isDateCorrect(string date);
    bool isLeapYear(int year);
    int numbersOfDaysInMonth(int month, int year);
    char selectOptionsFromAddExpenseMenu();
    void addExpenseFromCurrentDay();
    bool appendExpenseToFile(Expense expense);
    void addExpenseWithSelectedDate();
    void balanceOfCurrentMonth();
    void balanceOfPreviousMonth();
    //int convertDateIntoNumber(string date);
    void balanceOfSelectedPeriod();


};

#endif
