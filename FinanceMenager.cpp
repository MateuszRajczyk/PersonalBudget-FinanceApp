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
    DateMenager dateMenager;

    string date, item, amount;
    int dateYear, dateMonth, dateDay;
    int dateNumberForSort = 0;


    cout << "Podaj wybrana date: ";
    date = supplementaryMethods.loadTextLine();

    while(dateMenager.isDateCorrect(date) == false)
    {
        cout << "Niepoprawny format daty lub zakres! Podaj poprawna date: ";
        date = supplementaryMethods.loadTextLine();
    }

    expense.setDate(date);
    dateNumberForSort = dateMenager.convertDateIntoNumber(date);
    expense.setDateConvertionForSort(dateNumberForSort);

    expense.setUserId(ID_OF_LOGGED_USER);
    expense.setExpenseId((fileWithFinance.loadIdLastExpense()+1));

    cout << "Wydatek tytulem: ";
    item = supplementaryMethods.loadTextLine();
    item = supplementaryMethods.replaceFirstLetterForBigLetterAndRestForSmallLetters(item);
    expense.setItem(item);

    cout << "Kwota wydatku: ";
    amount = supplementaryMethods.loadTextLine();
    amount = supplementaryMethods.replaceAmountWithCommaForAmountWithDot(amount);
    expense.setAmount(amount);

    return expense;

}

Income FinanceMenager::enterDataOfNewIncomeWithSelectedDate()
{
    Income income;
    SupplementaryMethods supplementaryMethods;
    DateMenager dateMenager;

    string date, item, amount;
    int dateYear, dateMonth, dateDay;
    int dateNumberForSort = 0;


    cout << "Podaj wybrana date: ";
    date = supplementaryMethods.loadTextLine();

    while(dateMenager.isDateCorrect(date) == false)
    {
        cout << "Niepoprawny format daty lub zakres! Podaj poprawna date: ";
        date = supplementaryMethods.loadTextLine();
    }

    income.setDate(date);
    dateNumberForSort = dateMenager.convertDateIntoNumber(date);
    income.setDateConvertionForSort(dateNumberForSort);

    income.setUserId(ID_OF_LOGGED_USER);
    income.setIncomeId((fileWithFinance.loadIdLastIncome() + 1));

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
    DateMenager dateMenager;

    string date, item, amount;
    int dateNumberForSort = 0;

    expense.setUserId(ID_OF_LOGGED_USER);
    expense.setExpenseId((fileWithFinance.loadIdLastExpense() + 1));

    date = dateMenager.setDateInCorrectFormat(date);
    expense.setDate(date);

    dateNumberForSort = dateMenager.convertDateIntoNumber(date);
    expense.setDateConvertionForSort(dateNumberForSort);

    cout << "Wydatek tytulem: ";
    item = supplementaryMethods.loadTextLine();
    item = supplementaryMethods.replaceFirstLetterForBigLetterAndRestForSmallLetters(item);
    expense.setItem(item);

    cout << "Kwota wydatku: ";
    amount = supplementaryMethods.loadTextLine();
    amount = supplementaryMethods.replaceAmountWithCommaForAmountWithDot(amount);
    expense.setAmount(amount);

    return expense;
}

Income FinanceMenager::enterDataOfNewIncomeWithCurrentDate()
{
    Income income;
    SupplementaryMethods supplementaryMethods;
    DateMenager dateMenager;

    string date, item, amount;
    int dateNumberForSort = 0;
    income.setUserId(ID_OF_LOGGED_USER);
    income.setIncomeId(fileWithFinance.loadIdLastIncome() + 1);

    date = dateMenager.setDateInCorrectFormat(date);
    income.setDate(date);

    dateNumberForSort = dateMenager.convertDateIntoNumber(date);
    income.setDateConvertionForSort(dateNumberForSort);

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

void FinanceMenager::balanceOfCurrentMonth()
{
    Income income;
    Expense expense;
    int sumOfIncomes = 0;
    int sumOfExpenses = 0;

    sort(incomes.begin(), incomes.end(), [](Income &lhs, Income &rhs) {
      return lhs.loadDateConvertionForSort() < rhs.loadDateConvertionForSort();
    });

    sort(expenses.begin(), expenses.end(), [](Expense &lhs, Expense &rhs) {
      return lhs.loadDateConvertionForSort() < rhs.loadDateConvertionForSort();
    });

    cout << endl;
    cout << "Przychody" << endl;
    cout << "Data -- Tytul -- Kwota" << endl;
    cout << endl;

    sumOfIncomes = searchSavedDataIntoIncomesByCurrentMonth(sumOfIncomes);

    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Wydatki" << endl;
    cout << "Data -- Tytul -- Kwota" << endl;
    cout << endl;

    sumOfExpenses = searchSavedDataIntoExpensesByCurrentMonth(sumOfExpenses);

    showSumOfIncomesAndExpenses(sumOfIncomes, sumOfExpenses);

    system("pause");
}

int FinanceMenager::searchSavedDataIntoIncomesByCurrentMonth(int sumOfIncomes)
{
    SupplementaryMethods supplementaryMethods;
    DateMenager dateMenager;

    SYSTEMTIME st;
    GetSystemTime(&st);

    string date, dateYear, dateMonth;
    int checkDateYear, checkDateMonth;

    vector <Income>::iterator itr1;
    for(itr1 = incomes.begin(); itr1 != incomes.end(); itr1++)
    {
        date = itr1->loadDate();

        for(int i = 0; i < date.length(); i++)
        {
            if(i < 4)
            {
                dateYear += date[i];
            }
            else if((i > 4) && (i < 7))
            {
                dateMonth += date[i];
            }
        }

        checkDateYear = supplementaryMethods.conversionStringToInteger(dateYear);
        checkDateMonth = supplementaryMethods.conversionStringToInteger(dateMonth);

        if((checkDateYear == st.wYear) && (checkDateMonth == st.wMonth))
        {
            cout << itr1->loadDate() << " -- " << itr1->loadItem() << " -- " << itr1->loadAmount() << " " << "zl" << endl;
            sumOfIncomes += supplementaryMethods.conversionStringToInteger(itr1->loadAmount());
        }

        dateYear.clear();
        dateMonth.clear();
        date.clear();
    }

    return sumOfIncomes;
}

int FinanceMenager::searchSavedDataIntoExpensesByCurrentMonth(int sumOfExpenses)
{
    SupplementaryMethods supplementaryMethods;
    DateMenager dateMenager;

    SYSTEMTIME st;
    GetSystemTime(&st);

    string date, dateYear, dateMonth;
    int checkDateYear, checkDateMonth;

    vector <Expense>::iterator itr2;
    for(itr2 = expenses.begin(); itr2 != expenses.end(); itr2++)
    {
        date = itr2->loadDate();

        for(int i = 0; i < date.length(); i++)
        {
            if(i < 4)
            {
                dateYear += date[i];
            }
            else if((i > 4) && (i < 7))
            {
                dateMonth += date[i];
            }
        }

        checkDateYear = supplementaryMethods.conversionStringToInteger(dateYear);
        checkDateMonth = supplementaryMethods.conversionStringToInteger(dateMonth);

        if((checkDateYear == st.wYear) && (checkDateMonth == st.wMonth))
        {
            cout << itr2->loadDate() << " -- " << itr2->loadItem() << " -- " << itr2->loadAmount() << " " << "zl" << endl;
            sumOfExpenses += supplementaryMethods.conversionStringToInteger(itr2->loadAmount());
        }

        dateYear.clear();
        dateMonth.clear();
        date.clear();
    }

    return sumOfExpenses;
}

void FinanceMenager::showSumOfIncomesAndExpenses(int sumOfIncomes,int sumOfExpenses)
{
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "Suma przychodow: " << sumOfIncomes << " " << "zl" << endl;
    cout << endl;
    cout << "Suma wydatkow: " << sumOfExpenses << " " << "zl" << endl;
    cout << endl;
    if((sumOfIncomes - sumOfExpenses) > 0)
    {
        cout << "Oszczednosci: " << sumOfIncomes - sumOfExpenses << " " << "zl" << endl;
    }
    else if((sumOfIncomes - sumOfExpenses) < 0)
    {
        cout << "Straty: " << sumOfIncomes - sumOfExpenses << " " << "zl" << endl;
    }
    else
    {
        cout << "Oszczednosci / Straty: " << sumOfIncomes - sumOfExpenses << " " << "zl" << endl;
    }

    cout << endl;
}

void FinanceMenager::balanceOfPreviousMonth()
{
    Income income;
    Expense expense;
    int sumOfIncomes = 0;
    int sumOfExpenses = 0;

    sort(incomes.begin(), incomes.end(), [](Income &lhs, Income &rhs) {
      return lhs.loadDateConvertionForSort() < rhs.loadDateConvertionForSort();
    });

    sort(expenses.begin(), expenses.end(), [](Expense &lhs, Expense &rhs) {
      return lhs.loadDateConvertionForSort() < rhs.loadDateConvertionForSort();
    });

    cout << endl;
    cout << "Przychody" << endl;
    cout << "Data -- Tytul -- Kwota" << endl;
    cout << endl;

    sumOfIncomes = searchSavedDataIntoIncomesByPreviousMonth(sumOfIncomes);

    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Wydatki" << endl;
    cout << "Data -- Tytul -- Kwota" << endl;
    cout << endl;

    sumOfExpenses = searchSavedDataIntoExpensesByPreviousMonth(sumOfExpenses);

    showSumOfIncomesAndExpenses(sumOfIncomes, sumOfExpenses);

    system("pause");
}

int FinanceMenager::searchSavedDataIntoIncomesByPreviousMonth(int sumOfIncomes)
{
    SupplementaryMethods supplementaryMethods;
    DateMenager dateMenager;

    SYSTEMTIME st;
    GetSystemTime(&st);

    string date, dateYear, dateMonth;
    int checkDateYear, checkDateMonth;

    vector <Income>::iterator itr1;
    for(itr1 = incomes.begin(); itr1 != incomes.end(); itr1++)
    {
        date = itr1->loadDate();

        for(int i = 0; i < date.length(); i++)
        {
            if(i < 4)
            {
                dateYear += date[i];
            }
            else if((i > 4) && (i < 7))
            {
                dateMonth += date[i];
            }
        }

        checkDateYear = supplementaryMethods.conversionStringToInteger(dateYear);
        checkDateMonth = supplementaryMethods.conversionStringToInteger(dateMonth);

        if(st.wMonth == 1)
        {
            if((checkDateYear == st.wYear - 1) && (checkDateMonth == 12))
            {
                cout << itr1->loadDate() << " -- " << itr1->loadItem() << " -- " << itr1->loadAmount() << " " << "zl" << endl;
                sumOfIncomes += supplementaryMethods.conversionStringToInteger(itr1->loadAmount());
            }
        }
        else if((checkDateYear == st.wYear) && (checkDateMonth == (st.wMonth - 1)))
        {
            cout << itr1->loadDate() << " -- " << itr1->loadItem() << " -- " << itr1->loadAmount() << " " << "zl" << endl;
            sumOfIncomes += supplementaryMethods.conversionStringToInteger(itr1->loadAmount());
        }

        dateYear.clear();
        dateMonth.clear();
        date.clear();
    }

    return sumOfIncomes;
}

int FinanceMenager::searchSavedDataIntoExpensesByPreviousMonth(int sumOfExpenses)
{
    SupplementaryMethods supplementaryMethods;
    DateMenager dateMenager;

    SYSTEMTIME st;
    GetSystemTime(&st);

    string date, dateYear, dateMonth;
    int checkDateYear, checkDateMonth;

    vector <Expense>::iterator itr2;
    for(itr2 = expenses.begin(); itr2 != expenses.end(); itr2++)
    {
        date = itr2->loadDate();

        for(int i = 0; i < date.length(); i++)
        {
            if(i < 4)
            {
                dateYear += date[i];
            }
            else if((i > 4) && (i < 7))
            {
                dateMonth += date[i];
            }
        }

        checkDateYear = supplementaryMethods.conversionStringToInteger(dateYear);
        checkDateMonth = supplementaryMethods.conversionStringToInteger(dateMonth);

        if(st.wMonth == 1)
        {
            if((checkDateYear == st.wYear - 1) && (checkDateMonth == 12))
            {
                cout << itr2->loadDate() << " -- " << itr2->loadItem() << " -- " << itr2->loadAmount() << " " << "zl" << endl;
                sumOfExpenses += supplementaryMethods.conversionStringToInteger(itr2->loadAmount());
            }
        }
        else if((checkDateYear == st.wYear) && (checkDateMonth == (st.wMonth - 1)))
        {
            cout << itr2->loadDate() << " -- " << itr2->loadItem() << " -- " << itr2->loadAmount() << " " << "zl" << endl;
            sumOfExpenses += supplementaryMethods.conversionStringToInteger(itr2->loadAmount());
        }

        dateYear.clear();
        dateMonth.clear();
        date.clear();
    }

    return sumOfExpenses;
}

void FinanceMenager::balanceOfSelectedPeriod()
{
    Income income;
    Expense expense;
    SupplementaryMethods supplementaryMethods;
    int sumOfIncomes = 0;
    int sumOfExpenses = 0;
    int counter = 0;

    string dateFrom, dateTo;

    sort(incomes.begin(), incomes.end(), [](Income &lhs, Income &rhs) {
      return lhs.loadDateConvertionForSort() < rhs.loadDateConvertionForSort();
    });

    sort(expenses.begin(), expenses.end(), [](Expense &lhs, Expense &rhs) {
      return lhs.loadDateConvertionForSort() < rhs.loadDateConvertionForSort();
    });

    cout << endl;
    cout << "Okres czasu od daty (rrrr-mm-dd): ";
    dateFrom = supplementaryMethods.loadTextLine();
    cout << endl;
    cout << "Okres czasu do daty (rrrr-mm-dd): ";
    dateTo = supplementaryMethods.loadTextLine();

    cout << endl;
    cout << "Przychody" << endl;
    cout << "Data -- Tytul -- Kwota" << endl;
    cout << endl;

    sumOfIncomes = searchSavedDataIntoIncomesBySelectedPeriod(counter, sumOfIncomes, dateFrom, dateTo);

    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Wydatki" << endl;
    cout << "Data -- Tytul -- Kwota" << endl;
    cout << endl;

    sumOfExpenses = searchSavedDataIntoExpensesBySelectedPeriod(counter, sumOfExpenses, dateFrom, dateTo);

    showSumOfIncomesAndExpenses(sumOfIncomes, sumOfExpenses);

    system("pause");
}

int FinanceMenager::searchSavedDataIntoIncomesBySelectedPeriod(int counter, int sumOfIncomes, string dateFrom, string dateTo)
{
    SupplementaryMethods supplementaryMethods;
    DateMenager dateMenager;

    string date, dateYear, dateMonth, dateDay;
    string dateFromYear, dateFromMonth, dateFromDay;
    string dateToYear, dateToMonth, dateToDay;

    int checkDateYear, checkDateMonth, checkDateDay;
    int checkDateFromYear, checkDateFromMonth, checkDateFromDay;
    int checkDateToYear, checkDateToMonth, checkDateToDay;
    int checkYearCounter, checkMonthCounter, checkDayCounter;

    vector <Income>::iterator itr1;
    for(itr1 = incomes.begin(); itr1 != incomes.end(); itr1++)
    {
        date = itr1->loadDate();

        for(int i = 0; i < date.length(); i++)
        {
            if(i < 4)
            {
                dateYear += date[i];
                if(counter == 0)
                {
                    dateFromYear += dateFrom[i];
                    dateToYear += dateTo[i];
                }
            }
            else if((i > 4) && (i < 7))
            {
                dateMonth += date[i];
                if(counter == 0)
                {
                    dateFromMonth += dateFrom[i];
                    dateToMonth += dateTo[i];
                }
            }
            else if(i > 7)
            {
                dateDay += date[i];
                if(counter == 0)
                {
                    dateFromDay += dateFrom[i];
                    dateToDay += dateTo[i];
                }
            }
        }

        checkDateYear = supplementaryMethods.conversionStringToInteger(dateYear);
        checkDateMonth = supplementaryMethods.conversionStringToInteger(dateMonth);
        checkDateDay = supplementaryMethods.conversionStringToInteger(dateDay);

        if(counter == 0)
        {
            checkDateFromYear = supplementaryMethods.conversionStringToInteger(dateFromYear);
            checkDateFromMonth = supplementaryMethods.conversionStringToInteger(dateFromMonth);
            checkDateFromDay = supplementaryMethods.conversionStringToInteger(dateFromDay);

            checkDateToYear = supplementaryMethods.conversionStringToInteger(dateToYear);
            checkDateToMonth = supplementaryMethods.conversionStringToInteger(dateToMonth);
            checkDateToDay = supplementaryMethods.conversionStringToInteger(dateToDay);
        }

        counter++;

        checkYearCounter = checkDateFromYear;
        checkMonthCounter = checkDateFromMonth;
        checkDayCounter = checkDateFromDay;

        while((checkDateToYear != checkYearCounter) || (checkDateToMonth != checkMonthCounter) || (checkDateToDay != checkDayCounter))
        {
            if((checkYearCounter == checkDateYear) && (checkMonthCounter == checkDateMonth) && (checkDayCounter == checkDateDay))
            {
                    cout << itr1->loadDate() << " -- " << itr1->loadItem() << " -- " << itr1->loadAmount() << " " << "zl" << endl;
                    sumOfIncomes += supplementaryMethods.conversionStringToInteger(itr1->loadAmount());
                    break;
            }

            if(dateMenager.numbersOfDaysInMonth(checkMonthCounter, checkYearCounter) > checkDayCounter)
            {
                checkDayCounter++;
            }
            else if(checkMonthCounter < 12)
            {
                checkMonthCounter++;
                checkDayCounter = 1;
            }
            else
            {
                checkYearCounter++;
                checkDayCounter = 1;
                checkMonthCounter = 1;
            }
        }

        if((checkYearCounter == checkDateYear) && (checkMonthCounter == checkDateMonth) && (checkDayCounter == checkDateDay))
        {
            if((checkDateToYear == checkYearCounter) && (checkDateToMonth == checkMonthCounter) && (checkDateToDay == checkDayCounter))
            {
                cout << itr1->loadDate() << " -- " << itr1->loadItem() << " -- " << itr1->loadAmount() << " " << "zl" << endl;
                sumOfIncomes += supplementaryMethods.conversionStringToInteger(itr1->loadAmount());
            }
        }

        dateYear.clear();
        dateMonth.clear();
        dateDay.clear();
        date.clear();
    }

    return sumOfIncomes;
}

int FinanceMenager::searchSavedDataIntoExpensesBySelectedPeriod(int counter, int sumOfExpenses, string dateFrom, string dateTo)
{
    SupplementaryMethods supplementaryMethods;
    DateMenager dateMenager;

    string date, dateYear, dateMonth, dateDay;
    string dateFromYear, dateFromMonth, dateFromDay;
    string dateToYear, dateToMonth, dateToDay;

    int checkDateYear, checkDateMonth, checkDateDay;
    int checkDateFromYear, checkDateFromMonth, checkDateFromDay;
    int checkDateToYear, checkDateToMonth, checkDateToDay;
    int checkYearCounter, checkMonthCounter, checkDayCounter;

    vector <Expense>::iterator itr2;
    for(itr2 = expenses.begin(); itr2 != expenses.end(); itr2++)
    {
        date = itr2->loadDate();

        for(int i = 0; i < date.length(); i++)
        {
            if(i < 4)
            {
                dateYear += date[i];
                if(counter == 0)
                {
                    dateFromYear += dateFrom[i];
                    dateToYear += dateTo[i];
                }
            }
            else if((i > 4) && (i < 7))
            {
                dateMonth += date[i];
                if(counter == 0)
                {
                    dateFromMonth += dateFrom[i];
                    dateToMonth += dateTo[i];
                }
            }
            else if(i > 7)
            {
                dateDay += date[i];
                if(counter == 0)
                {
                    dateFromDay += dateFrom[i];
                    dateToDay += dateTo[i];
                }
            }
        }

        checkDateYear = supplementaryMethods.conversionStringToInteger(dateYear);
        checkDateMonth = supplementaryMethods.conversionStringToInteger(dateMonth);
        checkDateDay = supplementaryMethods.conversionStringToInteger(dateDay);

        if(counter == 0)
        {
            checkDateFromYear = supplementaryMethods.conversionStringToInteger(dateFromYear);
            checkDateFromMonth = supplementaryMethods.conversionStringToInteger(dateFromMonth);
            checkDateFromDay = supplementaryMethods.conversionStringToInteger(dateFromDay);

            checkDateToYear = supplementaryMethods.conversionStringToInteger(dateToYear);
            checkDateToMonth = supplementaryMethods.conversionStringToInteger(dateToMonth);
            checkDateToDay = supplementaryMethods.conversionStringToInteger(dateToDay);
        }

        counter++;

        checkYearCounter = checkDateFromYear;
        checkMonthCounter = checkDateFromMonth;
        checkDayCounter = checkDateFromDay;

        while((checkDateToYear != checkYearCounter) || (checkDateToMonth != checkMonthCounter) || (checkDateToDay != checkDayCounter))
        {
            if((checkYearCounter == checkDateYear) && (checkMonthCounter == checkDateMonth) && (checkDayCounter == checkDateDay))
            {
                    cout << itr2->loadDate() << " -- " << itr2->loadItem() << " -- " << itr2->loadAmount() << " " << "zl" << endl;
                    sumOfExpenses += supplementaryMethods.conversionStringToInteger(itr2->loadAmount());
                    break;
            }

            if(dateMenager.numbersOfDaysInMonth(checkMonthCounter, checkYearCounter) > checkDayCounter)
            {
                checkDayCounter++;
            }
            else if(checkMonthCounter < 12)
            {
                checkMonthCounter++;
                checkDayCounter = 1;
            }
            else
            {
                checkYearCounter++;
                checkDayCounter = 1;
                checkMonthCounter = 1;
            }
        }

        if((checkYearCounter == checkDateYear) && (checkMonthCounter == checkDateMonth) && (checkDayCounter == checkDateDay))
        {
            if((checkDateToYear == checkYearCounter) && (checkDateToMonth == checkMonthCounter) && (checkDateToDay == checkDayCounter))
            {
                cout << itr2->loadDate() << " -- " << itr2->loadItem() << " -- " << itr2->loadAmount() << " " << "zl" << endl;
                sumOfExpenses += supplementaryMethods.conversionStringToInteger(itr2->loadAmount());
            }
        }

        dateYear.clear();
        dateMonth.clear();
        dateDay.clear();
        date.clear();
    }

    return sumOfExpenses;
}
