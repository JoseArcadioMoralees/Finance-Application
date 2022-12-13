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

void UsersManager::logAUser()
{
    users = usersFile.loadFromFile();

    string login;

    for (int i = 0; i < 3; i++)
    {
        cout << "Podaj login: ";
        cin >> login;
        if (AuxiliaryFunctions::checkLogin(login, users))
        {
            cout << "Zalogowales sie" << endl;
            i = 3;
            system("pause");
        }
        else
        {
            cout << "Podales bledny login. Sprobuj ponownie. Liczba pozostalych prob: " << 2 - i
                 << endl;
            system("pause");
        }
    }
}

void UsersManager::showUsers()
{
    users = usersFile.loadFromFile();

    Users user;
    for (unsigned int i = 0; i < users.size(); i++)
    {
        user = users[i];

        cout << "ID: " << user.getUserId() << endl;
        cout << "Login: " << user.getLogin() << endl;
        cout << "Password: " << user.getPassword() << endl;
        cout << "Name: " << user.getName() << endl;
        cout << "Surname: " << user.getSurname() << endl
             << endl;
    }
}