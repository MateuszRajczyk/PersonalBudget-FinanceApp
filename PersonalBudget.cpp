#include "PersonalBudget.h"

void PersonalBudget::userRegister()
{
    userMenager.userRegister();
}

void PersonalBudget::userLogin()
{
    userMenager.userLogin();
    /*
    if(uzytkownikMenager.czyUzytkownikJestZalogowany())
    {
        adresatMenager = new AdresatMenager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());
    }
    */
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
    cout << "9. Koniec programu" << endl;
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
     //delete adresatMenager;
     //adresatMenager = NULL;
 }
