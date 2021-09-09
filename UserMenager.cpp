#include "UserMenager.h"

void UserMenager::userRegister()
{
    User user = enterDataOfNewUser();

    users.push_back(user);
    fileWithUsers.appendUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserMenager::enterDataOfNewUser()
{
    User user;
    SupplementaryMethods supplementaryMethods;

    user.setUserId(loadIdOfNewUser());

    cout << "Podaj imie: ";
    user.setName(supplementaryMethods.loadTextLine());

    cout << "Podaj nazwisko: ";
    user.setSurname(supplementaryMethods.loadTextLine());

    do
    {
        cout << "Podaj login: ";
        user.setLogin(supplementaryMethods.loadTextLine());
    } while (isLoginExist(user.loadLogin()) == true);


    cout << "Podaj haslo: ";
    user.setPassword(supplementaryMethods.loadTextLine());

    return user;
}

int UserMenager::loadIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().loadUserId() + 1;
}

bool UserMenager::isLoginExist(string login)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].loadLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UserMenager::userLogin()
{
    SupplementaryMethods supplementaryMethods;
    string login = "";
    string password = "";

    cout << endl << "Podaj login: ";
    login = supplementaryMethods.loadTextLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> loadLogin() == login)
        {
            for (int numberOfTests = 3; numberOfTests > 0; numberOfTests--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfTests << ": ";
                password = supplementaryMethods.loadTextLine();

                if (itr -> loadPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idOfLoggedUser = itr -> loadUserId();
                    return idOfLoggedUser;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

int UserMenager::loadIdOfLoggedUser()
{
    return idOfLoggedUser;
}

void UserMenager::changePasswordOfLoggedUser()
{
    if(idOfLoggedUser > 0)
    {
        SupplementaryMethods supplementaryMethods;
        string newPassword = "";
        cout << "Podaj nowe haslo: ";
        newPassword = supplementaryMethods.loadTextLine();

        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            if (itr -> loadUserId() == idOfLoggedUser)
            {
                itr -> setPassword(newPassword);
                cout << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
            }
        }
        fileWithUsers.saveAllUsersToFile(idOfLoggedUser, newPassword);
    }
    else
    {
        cout << "Aby zmienic haslo, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

void UserMenager::userLoggingOut()
{
    idOfLoggedUser = 0;
}

bool UserMenager::isUserLoggedIn()
{
    if(idOfLoggedUser > 0)
        return true;
    else
        return false;
}


