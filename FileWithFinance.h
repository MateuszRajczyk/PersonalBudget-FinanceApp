#ifndef FILEWITHFINANCE_H
#define FILEWITHFINANCE_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "Expense.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include "SupplementaryMethods.h"
#include "Markup.h"

using namespace std;

class FileWithFinance
{
    const string NAME_FILE_WITH_INCOMES;
    const string NAME_FILE_WITH_EXPENSES;
    int idLastIncome;
    int idLastExpense;
public:
    FileWithFinance(string nameFileWithIncomes, string nameFileWithExpenses) : NAME_FILE_WITH_INCOMES(nameFileWithIncomes), NAME_FILE_WITH_EXPENSES(nameFileWithExpenses) {
        idLastIncome = 0;
        idLastExpense = 0;
    };
    void readIdLastIncome();
    void readIdLastExpense();
    int convertDateIntoNumber(string date);
    int loadIdLastIncome();
    int setIdLastIncome(int newIdLastIncome);
    int loadIdLastExpense();
    int setIdLastExpense(int newIdLastExpense);
    bool appendIncomeToFile(Income income);
    bool appendExpenseToFile(Expense expense);
    vector<Income> loadIncomesOfLoggedUserFromFile(int idOfLoggedUser);
    vector<Expense> loadExpensesOfLoggedUserFromFile(int idOfLoggedUser);
};

#endif
