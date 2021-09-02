#include "FileWithUsers.h"
#include <windows.h>

void FileWithUsers::appendUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "User" );
    xml.IntoElem();
    xml.AddElem( "name", user.loadName());
    xml.AddElem( "surname", user.loadSurname());
    xml.AddElem( "userId", user.loadUserId() );
    xml.AddElem( "login", user.loadLogin());
    xml.AddElem( "password", user.loadPassword());

    xml.Save("users.xml");
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    CMarkup xml;
    User user;
    SupplementaryMethods supplementaryMethods;
    vector<User>users;

    xml.Load( "users.xml" );

    xml.ResetPos();

    xml.FindElem();

    xml.IntoElem();

    while ( xml.FindElem("User") )
    {
        xml.FindChildElem( "name" );
        user.setName(xml.GetChildData());

        xml.FindChildElem( "surname" );
        user.setSurname(xml.GetChildData());

        xml.FindChildElem("userId");
        user.setUserId(supplementaryMethods.conversionStringToInteger(xml.GetChildData()));

        xml.FindChildElem("login");
        user.setLogin(xml.GetChildData());

        xml.FindChildElem("password");
        user.setPassword(xml.GetChildData());

        users.push_back(user);
    }
    return users;

}

void FileWithUsers::saveAllUsersToFile(int idOfLoggedUser, string newPassword)
{
    CMarkup xml;
    SupplementaryMethods supplementaryMethods;

    xml.Load( "users.xml" );

    xml.ResetPos();

    xml.FindElem();

    xml.IntoElem();

    while ( xml.FindElem("User") )
    {
        xml.FindChildElem("userId");
        if(idOfLoggedUser == supplementaryMethods.conversionStringToInteger(xml.GetChildData()))
        {
            xml.FindChildElem("password");
            xml.RemoveChildElem();
            xml.AddChildElem("password", newPassword);
        }
    }

    xml.Save("users.xml");
}
