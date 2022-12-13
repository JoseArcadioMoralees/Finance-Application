#include "UsersFile.h"

void UsersFile::saveToFile()
{
    Users user;
    int id;
    cout << "Podaj ID: ";
    cin >> id;
    user.setUserId(id);

    string login;
    cout << "Podaj login: ";
    cin >> login;
    user.setLogin(login);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);

    // users.push_back(user);

    CMarkup xml;

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

void UsersFile::loadFromFile()
{
    CMarkup xml;
    Users user;

    if (xml.Load("users.xml"))
    {
        xml.FindElem();
        xml.IntoElem();

        xml.FindElem("Users");
        xml.IntoElem();
        xml.FindElem("User");
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

        cout << user.getUserId() << endl; 
        cout << user.getLogin() << endl;
        cout << user.getPassword() << endl;
        cout << user.getName() << endl;
        cout << user.getSurname() << endl;    
    }

}