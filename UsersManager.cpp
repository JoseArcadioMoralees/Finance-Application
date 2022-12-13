#include "UsersManager.h"

void UsersManager::registerNewUser()
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

    users.push_back(user); 

    usersFile.saveToFile(users); 
}