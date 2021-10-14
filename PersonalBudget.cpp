#include "PersonalBudget.h"

void PersonalBudget::userRegister()
{
    userMenager.userRegister();
}

void PersonalBudget::userLogin()
{
    userMenager.userLogin();

    financeMenager = new FinanceMenager(NAME_FILE_WITH_INCOMES, NAME_FILE_WITH_EXPENSES, userMenager.loadIdOfLoggedUser());
}

char PersonalBudget::selectOptionsFromRegisterMenu()
{
    SupplementaryMethods supplementaryMethods;
    char select;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "3. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    select = supplementaryMethods.loadCharacter();

    return select;
}

int PersonalBudget::loadIdOfLoggedUser()
{
    return userMenager.loadIdOfLoggedUser();
}

char PersonalBudget::selectOptionsFromUserMenu()
{
    SupplementaryMethods supplementaryMethods;
    char select;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z poprzedniego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = supplementaryMethods.loadCharacter();

    return select;
}

void PersonalBudget::changePasswordOfLoggedUser()
 {
    userMenager.changePasswordOfLoggedUser();
 }

void PersonalBudget::userLoggingOut()
 {
    userMenager.userLoggingOut();

    delete financeMenager;
    financeMenager = NULL;
 }

void PersonalBudget::addIncome()
{
    financeMenager->addNewIncome();
}

void PersonalBudget::addExpense()
{
    financeMenager->addNewExpense();
}

void PersonalBudget::balanceOfCurrentMonth()
{
    financeMenager->balanceOfCurrentMonth();
}

void PersonalBudget::balanceOfSelectedPeriod()
{
    financeMenager->balanceOfSelectedPeriod();
}

void PersonalBudget::balanceOfPreviousMonth()
{
    financeMenager->balanceOfPreviousMonth();
}
