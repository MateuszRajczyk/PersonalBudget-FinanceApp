#include "FinanceMenager.h"

void FinanceMenager::addNewIncome()
{
    system("cls");

    char select;

    select = selectOptionsFromAddIncomeMenu();

    switch(select)
    {
    case '1':
        addIncomeFromCurrentDay();
        break;
    case '2':
        addIncomeWithSelectedDate();
        break;
    case '3':
        cout << endl << "Powrot do menu uzytkownika" << endl << endl;
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
        break;
    }
}

void FinanceMenager::addNewExpense()
{
    system("cls");

    char select;

    select = selectOptionsFromAddExpenseMenu();

    switch(select)
    {
    case '1':
        addExpenseFromCurrentDay();
        break;
    case '2':
        addExpenseWithSelectedDate();
        break;
    case '3':
        cout << endl << "Powrot do menu uzytkownika" << endl << endl;
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
        break;
    }
}

void FinanceMenager::addExpenseFromCurrentDay()
{
    Expense expense;

    vector<Expense>expenses;

    system("cls");

    cout << " >>> DODAWANIE WYDATKU Z DZISIEJSZA DATA <<<" << endl << endl;
    expense = enterDataOfNewExpenseWithCurrentDate();


    expenses.push_back(expense);

    if(fileWithFinance.appendExpenseToFile(expense) == true)
    {
        cout << "Nowy wydatek zostal dodany" << endl;
    }
    else
        cout << "Blad. Nie udalo sie dodac nowego wydatku do pliku" << endl;
    system("pause");
}

void FinanceMenager::addExpenseWithSelectedDate()
{
    Expense expense;

    vector<Expense>expenses;

    system("cls");

    cout << " >>> DODAWANIE WYDATKU Z WYBRANA DATA <<<" << endl << endl;
    expense = enterDataOfNewExpenseWithSelectedDate();


    expenses.push_back(expense);

    if(fileWithFinance.appendExpenseToFile(expense) == true)
    {
        cout << "Nowy wydatek zostal dodany" << endl;
    }
    else
        cout << "Blad. Nie udalo sie dodac nowego wydatku do pliku" << endl;
    system("pause");
}


void FinanceMenager::addIncomeWithSelectedDate()
{
    Income income;

    vector<Income>incomes;

    system("cls");

    cout << " >>> DODAWANIE PRZYCHODU Z WYBRANA DATA <<<" << endl << endl;
    income = enterDataOfNewIncomeWithSelectedDate();


    incomes.push_back(income);

    if(fileWithFinance.appendIncomeToFile(income) == true)
    {
        cout << "Nowy przychod zostal dodany" << endl;
    }
    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku" << endl;
    system("pause");
}

void FinanceMenager::addIncomeFromCurrentDay()
{
    Income income;

    vector<Income>incomes;

    system("cls");

    cout << " >>> DODAWANIE PRZYCHODU Z DZISIEJSZA DATA <<<" << endl << endl;
    income = enterDataOfNewIncomeWithCurrentDate();


    incomes.push_back(income);

    if(fileWithFinance.appendIncomeToFile(income) == true)
    {
        cout << "Nowy przychod zostal dodany" << endl;
    }
    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku" << endl;
    system("pause");
}

Expense FinanceMenager::enterDataOfNewExpenseWithSelectedDate()
{
    Expense expense;
    SupplementaryMethods supplementaryMethods;

    string date, item, amount;
    int dateYear, dateMonth, dateDay;


    cout << "Podaj wybrana date: ";
    date = supplementaryMethods.loadTextLine();

    while(isDateCorrect(date) == false)
    {
        cout << "Niepoprawny format daty lub zakres! Podaj poprawna date: ";
        date = supplementaryMethods.loadTextLine();
    }

    expense.setDate(date);

    expense.setUserId(ID_OF_LOGGED_USER);
    expense.setExpenseId((fileWithFinance.loadIdLastExpense()+1));

    cout << "Przychod tytulem: ";
    item = supplementaryMethods.loadTextLine();
    item = supplementaryMethods.replaceFirstLetterForBigLetterAndRestForSmallLetters(item);
    expense.setItem(item);

    cout << "Kwota przychodu: ";
    amount = supplementaryMethods.loadTextLine();
    amount = supplementaryMethods.replaceAmountWithCommaForAmountWithDot(amount);
    expense.setAmount(amount);

    return expense;

}

Income FinanceMenager::enterDataOfNewIncomeWithSelectedDate()
{
    Income income;
    SupplementaryMethods supplementaryMethods;

    string date, item, amount;
    int dateYear, dateMonth, dateDay;


    cout << "Podaj wybrana date: ";
    date = supplementaryMethods.loadTextLine();

    while(isDateCorrect(date) == false)
    {
        cout << "Niepoprawny format daty lub zakres! Podaj poprawna date: ";
        date = supplementaryMethods.loadTextLine();
    }

    income.setDate(date);

    income.setUserId(ID_OF_LOGGED_USER);
    income.setIncomeId((fileWithFinance.loadIdLastIncome()+1));

    cout << "Przychod tytulem: ";
    item = supplementaryMethods.loadTextLine();
    item = supplementaryMethods.replaceFirstLetterForBigLetterAndRestForSmallLetters(item);
    income.setItem(item);

    cout << "Kwota przychodu: ";
    amount = supplementaryMethods.loadTextLine();
    amount = supplementaryMethods.replaceAmountWithCommaForAmountWithDot(amount);
    income.setAmount(amount);

    return income;

}

Expense FinanceMenager::enterDataOfNewExpenseWithCurrentDate()
{
    Expense expense;
    SupplementaryMethods supplementaryMethods;
    SYSTEMTIME st;
    GetSystemTime(&st);

    string date, item, amount;

    expense.setUserId(ID_OF_LOGGED_USER);
    expense.setExpenseId((fileWithFinance.loadIdLastExpense() + 1));

    if((st.wMonth < 10) && (st.wDay < 10))
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wDay);
        expense.setDate(date);
    }
    else if(st.wMonth < 10)
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + supplementaryMethods.conversionIntegerToString(st.wDay);
        expense.setDate(date);
    }
    else if(st.wDay < 10)
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wDay);
        expense.setDate(date);
    }
    else
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + supplementaryMethods.conversionIntegerToString(st.wDay);
        expense.setDate(date);
    }

    cout << "Przychod tytulem: ";
    item = supplementaryMethods.loadTextLine();
    item = supplementaryMethods.replaceFirstLetterForBigLetterAndRestForSmallLetters(item);
    expense.setItem(item);

    cout << "Kwota przychodu: ";
    amount = supplementaryMethods.loadTextLine();
    amount = supplementaryMethods.replaceAmountWithCommaForAmountWithDot(amount);
    expense.setAmount(amount);

    return expense;
}

Income FinanceMenager::enterDataOfNewIncomeWithCurrentDate()
{
    Income income;
    SupplementaryMethods supplementaryMethods;
    SYSTEMTIME st;
    GetSystemTime(&st);

    string date, item, amount;

    income.setUserId(ID_OF_LOGGED_USER);
    income.setIncomeId((fileWithFinance.loadIdLastIncome()+1));

    if((st.wMonth < 10) && (st.wDay < 10))
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wDay);
        income.setDate(date);
    }
    else if(st.wMonth < 10)
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + supplementaryMethods.conversionIntegerToString(st.wDay);
        income.setDate(date);
    }
    else if(st.wDay < 10)
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wDay);
        income.setDate(date);
    }
    else
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + supplementaryMethods.conversionIntegerToString(st.wDay);
        income.setDate(date);
    }

    cout << "Przychod tytulem: ";
    item = supplementaryMethods.loadTextLine();
    item = supplementaryMethods.replaceFirstLetterForBigLetterAndRestForSmallLetters(item);
    income.setItem(item);

    cout << "Kwota przychodu: ";
    amount = supplementaryMethods.loadTextLine();
    amount = supplementaryMethods.replaceAmountWithCommaForAmountWithDot(amount);
    income.setAmount(amount);

    return income;
}

char FinanceMenager::selectOptionsFromAddIncomeMenu()
{
    SupplementaryMethods supplementaryMethods;

    char select;

    cout << "   >>> MENU DODAJ PRZYCHOD <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod z dzisiejsza data" << endl;
    cout << "2. Dodaj przychod z wybrana data" << endl;
    cout << "3 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    select = supplementaryMethods.loadCharacter();

    return select;
}

char FinanceMenager::selectOptionsFromAddExpenseMenu()
{
    SupplementaryMethods supplementaryMethods;

    char select;

    cout << "   >>> MENU DODAJ WYDATEK <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj wydatek z dzisiejsza data" << endl;
    cout << "2. Dodaj wydatek z wybrana data" << endl;
    cout << "3 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    select = supplementaryMethods.loadCharacter();

    return select;
}

bool FinanceMenager::isDateCorrect(string date)
{
    SupplementaryMethods supplementaryMethods;
    SYSTEMTIME st;
    GetSystemTime(&st);

    string dateYear, dateMonth, dateDay;
    int checkDateYear, checkDateMonth, checkDateDay;

    for(int i = 0; i < date.length(); i++)
    {
        if((date[4] != '-') || (date[7] != '-'))
        {
            return false;
        }
        else if(i < 4)
        {
            dateYear += date[i];
        }
        else if((i > 4) && (i < 7))
        {
            dateMonth += date[i];
        }
        else if(i > 7)
        {
            dateDay += date[i];
        }
    }

    checkDateYear = supplementaryMethods.conversionStringToInteger(dateYear);
    checkDateMonth = supplementaryMethods.conversionStringToInteger(dateMonth);
    checkDateDay = supplementaryMethods.conversionStringToInteger(dateDay);

    if(((checkDateYear >= 2000) && (checkDateYear <= st.wYear)) && ((checkDateMonth >= 1) && (checkDateMonth <= 12)) && (numbersOfDaysInMonth(checkDateMonth, checkDateYear) >= checkDateDay))
    {
        if(checkDateYear == st.wYear)
        {
            if(checkDateMonth <= st.wMonth)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
}

int FinanceMenager::numbersOfDaysInMonth(int month, int year)
{
    switch(month)
    {
    case 1:
        return 31;
        break;
    case 2:
        if(isLeapYear(year) == true)
        {
            return 29;
            break;
        }
        else
        {
            return 28;
            break;
        }
        break;
    case 3:
        return 31;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 31;
        break;
    case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
    case 12:
        return 31;
        break;
    }
}

bool FinanceMenager::isLeapYear(int year)
{
    if(year == 2000)
    {
        return true;
    }
    else if(year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
