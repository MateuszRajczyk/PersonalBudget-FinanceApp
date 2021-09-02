#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include "User.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include "SupplementaryMethods.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
    const string NAME_FILE_WITH_USERS;

public:
    FileWithUsers(string nameFileWithUsers) : NAME_FILE_WITH_USERS(nameFileWithUsers) {};
    void appendUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(int idOfLoggedUser, string newPassword);

};

#endif
