#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserMenager.h"
#include "FinanceMenager.h"
#include "FileWithFinance.h"


using namespace std;

class PersonalBudget
{
    UserMenager userMenager;
    FinanceMenager *financeMenager;

    const string NAME_FILE_WITH_INCOMES;
    const string NAME_FILE_WITH_EXPENSES;


public:
    PersonalBudget(string nameFileWithUsers, string nameFileWithIncomes, string nameFileWithExpenses) : userMenager(nameFileWithUsers), NAME_FILE_WITH_INCOMES(nameFileWithIncomes), NAME_FILE_WITH_EXPENSES(nameFileWithExpenses)
    {
        financeMenager = NULL;
    };
    ~PersonalBudget()
    {
        delete financeMenager;
        financeMenager = NULL;
    };
    void userRegister();
    void userLogin();
    char selectOptionsFromRegisterMenu();
    int loadIdOfLoggedUser();
    char selectOptionsFromUserMenu();
    void changePasswordOfLoggedUser();
    void userLoggingOut();
    void addIncome();
    void addExpense();


};


#endif
