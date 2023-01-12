#include "UsersFile.h"

void UsersFile::saveToFile(Users user)
{
    bool fileExists = xml.Load("users.xml");

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save("users.xml");
}

vector<Users> UsersFile::loadFromFile()
{
    Users user;
    vector<Users> users;

    if (xml.Load("users.xml"))
    {
        xml.FindElem();
        xml.IntoElem();

        xml.FindElem("Users");
        xml.IntoElem();
        while (xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setUserId(atoi(xml.GetData().c_str()));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.FindElem("Name");
            user.setName(xml.GetData());
            xml.FindElem("Surname");
            user.setSurname(xml.GetData());
            xml.OutOfElem();

            users.push_back(user);
        }
    }

    return users;
}
