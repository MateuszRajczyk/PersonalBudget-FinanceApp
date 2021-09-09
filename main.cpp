#include <iostream>
#include "Markup.h"
#include <windows.h>
#include <winbase.h>

#include "PersonalBudget.h"
#include "UserMenager.h"
#include "User.h"

using namespace std;

int main()
{

    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    char select;

    while (true)
    {
        if (personalBudget.loadIdOfLoggedUser() == 0)
        {
            select = personalBudget.selectOptionsFromRegisterMenu();

            switch (select)
            {
            case '1':
                personalBudget.userRegister();
                break;
            case '2':
                personalBudget.userLogin();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            select = personalBudget.selectOptionsFromUserMenu();

            switch (select)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':

                break;
            case '4':

                break;
            case '5':

                break;
            case '6':
                personalBudget.changePasswordOfLoggedUser();
                break;
            case '7':
                personalBudget.userLoggingOut();
                break;
            }
        }
    }

    return 0;
}
