#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserMenager.h"


using namespace std;

class PersonalBudget
{
    UserMenager userMenager;

public:
    PersonalBudget(string nameFileWithUsers) : userMenager(nameFileWithUsers){};
    void userRegister();
    void userLogin();
    char selectOptionsFromRegisterMenu();
    int loadIdOfLoggedUser();
    char selectOptionsFromUserMenu();
    void changePasswordOfLoggedUser();
    void userLoggingOut();


};


#endif
