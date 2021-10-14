#include "FileWithFinance.h"
#include "windows.h"
#include "FinanceMenager.h"
#include "DateMenager.h"

int FileWithFinance::loadIdLastIncome()
{
    return idLastIncome;
}

int FileWithFinance::setIdLastIncome(int newIdLastIncome)
{
    idLastIncome = newIdLastIncome;
}

int FileWithFinance::loadIdLastExpense()
{
    return idLastExpense;
}

int FileWithFinance::setIdLastExpense(int newIdLastExpense)
{
    idLastExpense = newIdLastExpense;
}

bool FileWithFinance::appendIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExists = xml.Load(NAME_FILE_WITH_INCOMES);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        fileExists = true;
    }

    if(fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "Income" );
        xml.IntoElem();
        xml.AddElem( "userId", income.loadUserId());
        xml.AddElem( "incomeId", income.loadIncomeId());
        xml.AddElem( "date", income.loadDate());
        xml.AddElem( "item", income.loadItem());
        xml.AddElem( "amount", income.loadAmount());

        xml.Save("incomes.xml");

        idLastIncome++;

        return true;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
        return false;
    }
}

bool FileWithFinance::appendExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load(NAME_FILE_WITH_EXPENSES);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
        fileExists = true;
    }

    if(fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "Expense" );
        xml.IntoElem();
        xml.AddElem( "userId", expense.loadUserId());
        xml.AddElem( "expenseId", expense.loadExpenseId());
        xml.AddElem( "date", expense.loadDate());
        xml.AddElem( "item", expense.loadItem());
        xml.AddElem( "amount", expense.loadAmount());

        xml.Save("expenses.xml");

        idLastExpense++;

        return true;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
        return false;
    }
}

vector<Income> FileWithFinance::loadIncomesOfLoggedUserFromFile(int idOfLoggedUser)
{
    CMarkup xml;
    vector<Income> incomes;
    Income income;
    SupplementaryMethods supplementaryMethods;
    DateMenager dateMenager;
    int dateNumberForSort = 0;

    xml.Load( "incomes.xml" );

    xml.ResetPos();

    xml.FindElem();

    xml.IntoElem();

    while ( xml.FindElem("Income") )
    {
        xml.FindChildElem( "userId" );

        if(idOfLoggedUser == supplementaryMethods.conversionStringToInteger(xml.GetChildData()))
        {
            income.setUserId(supplementaryMethods.conversionStringToInteger(xml.GetChildData()));

            xml.FindChildElem( "incomeId" );
            income.setIncomeId(supplementaryMethods.conversionStringToInteger(xml.GetChildData()));

            xml.FindChildElem( "date" );
            income.setDate(xml.GetChildData());
            dateNumberForSort = dateMenager.convertDateIntoNumber(xml.GetChildData());
            income.setDateConvertionForSort(dateNumberForSort);

            xml.FindChildElem( "item" );
            income.setItem(xml.GetChildData());

            xml.FindChildElem( "amount" );
            income.setAmount(xml.GetChildData());

            incomes.push_back(income);
        }
    }
    return incomes;
}

void FileWithFinance::readIdLastIncome()
{
    CMarkup xml;
    SupplementaryMethods supplementaryMethods;

    xml.Load( "incomes.xml" );

    xml.ResetPos();

    xml.FindElem();

    xml.IntoElem();

    while ( xml.FindElem("Income") )
    {
        xml.FindChildElem( "incomeId" );
        idLastIncome = supplementaryMethods.conversionStringToInteger(xml.GetChildData());
    }
}

vector<Expense> FileWithFinance::loadExpensesOfLoggedUserFromFile(int idOfLoggedUser)
{
    CMarkup xml;
    vector<Expense> expenses;
    Expense expense;
    SupplementaryMethods supplementaryMethods;
    DateMenager dateMenager;
    int dateNumberForSort = 0;

    xml.Load( "expenses.xml" );

    xml.ResetPos();

    xml.FindElem();

    xml.IntoElem();

    while ( xml.FindElem("Expense") )
    {
        xml.FindChildElem( "userId" );

        if(idOfLoggedUser == supplementaryMethods.conversionStringToInteger(xml.GetChildData()))
        {
            expense.setUserId(supplementaryMethods.conversionStringToInteger(xml.GetChildData()));

            xml.FindChildElem( "expenseId" );
            expense.setExpenseId(supplementaryMethods.conversionStringToInteger(xml.GetChildData()));

            xml.FindChildElem( "date" );
            expense.setDate(xml.GetChildData());
            dateNumberForSort = dateMenager.convertDateIntoNumber(xml.GetChildData());
            expense.setDateConvertionForSort(dateNumberForSort);

            xml.FindChildElem( "item" );
            expense.setItem(xml.GetChildData());

            xml.FindChildElem( "amount" );
            expense.setAmount(xml.GetChildData());

            expenses.push_back(expense);
        }
    }
    return expenses;
}

void FileWithFinance::readIdLastExpense()
{
    CMarkup xml;
    SupplementaryMethods supplementaryMethods;

    xml.Load( "expenses.xml" );

    xml.ResetPos();

    xml.FindElem();

    xml.IntoElem();

    while ( xml.FindElem("Expense") )
    {
        xml.FindChildElem( "expenseId" );
        idLastExpense = supplementaryMethods.conversionStringToInteger(xml.GetChildData());
    }
}
