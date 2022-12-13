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

    //users.push_back(user); 

    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

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