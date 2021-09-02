#include "User.h"

void User::setUserId(int newUserId)
{
    if(newUserId >= 0)
        userId = newUserId;
}

void User::setLogin(string newLogin)
{
    login = newLogin;
}

void User::setPassword(string newPassword)
{
    password = newPassword;
}

void User::setName(string newName)
{
    name = newName;
}

void User::setSurname(string newSurname)
{
    surname = newSurname;
}

int User::loadUserId()
{
    return userId;
}

string User::loadLogin()
{
    return login;
}

string User::loadPassword()
{
    return password;
}

string User::loadName()
{
    return name;
}

string User::loadSurname()
{
    return surname;
}
