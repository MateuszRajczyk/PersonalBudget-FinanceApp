#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "FileWithUsers.h"
#include "FinanceMenager.h"
#include "FileWithFinance.h"
#include "User.h"
#include "SupplementaryMethods.h"
#include "FileWithUsers.h"



using namespace std;

class UserMenager
{
    int idOfLoggedUser;
    vector<User>users;
    User user;
    FileWithUsers fileWithUsers;



    User enterDataOfNewUser();
    int loadIdOfNewUser();
    bool isLoginExist(string login);
public:
    UserMenager(string nameFileWithUsers, int idOfLoggedUser = 0) : fileWithUsers(nameFileWithUsers), idOfLoggedUser(idOfLoggedUser)  {
        idOfLoggedUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void userRegister();
    int userLogin();
    int loadIdOfLoggedUser();
    void changePasswordOfLoggedUser();
    void userLoggingOut();
};

#endif
