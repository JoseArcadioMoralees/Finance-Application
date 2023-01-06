#include "UsersManager.h"

void UsersManager::registerNewUser()
{
    Users user;
    user.setUserId(addUsersId());

    user.setLogin(checkIfLoginExists());

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

    usersFile.saveToFile(user);
}

void UsersManager::logAUser()
{

    string login;
    string password;

    for (int i = 0; i < 3; i++)
    {
        cout << "Podaj login: ";
        cin >> login;
        if (checkLogin(login, users))
        {
            usersLogin = login;
            for (int j = 0; j < 3; j++)
            {
                cout << "Podaj haslo: ";
                cin >> password;
                if (checkPassword(password, users))
                {
                    j = 3;
                    i = 3;
                    cout << "Zalogowales sie." << endl;
                    system("Pause");
                }
                else
                {
                    if (j != 2)
                    {
                        cout << "Bledne haslo. Pozostala ilosc prob: " << 2 - j << endl;
                    }

                    if (j == 2)
                    {
                        i = 3;
                        cout << "Przekroczyles limit prob. Sprobuj innym razem." << endl;
                    }
                    system("Pause");
                }
            }
        }
        else
        {
            if (i != 2)
            {
                cout << "Login niepoprawny. Pozostala ilosc prob: " << 2 - i << endl;
            }
            else
            {
                cout << "Przekroczyles limit prob. Sprobuj ponownie pozniej." << endl;
            }

            system("Pause");
        }
    }
}

void UsersManager::showUsers()
{
    for (unsigned int i = 0; i < users.size(); i++)
    {

        cout << "ID: " << users[i].getUserId() << endl;
        cout << "Login: " << users[i].getLogin() << endl;
        cout << "Password: " << users[i].getPassword() << endl;
        cout << "Name: " << users[i].getName() << endl;
        cout << "Surname: " << users[i].getSurname() << endl
             << endl;
    }
    system("Pause"); 
}

bool UsersManager::checkLogin(string login, vector<Users> users)
{
    bool flag = false; 
    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (login == users[i].getLogin())
        {
            flag = true; 
            break;
        }
    }

    return flag; 
}

bool UsersManager::checkPassword(string password, vector<Users> users)
{
    bool flag = false; 
    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (usersLogin == users[i].getLogin() && password == users[i].getPassword())
        {
            idOfLoggedUser = users[i].getUserId();
            flag = true; 
            break;
        }
    }
    return flag; 
}

string UsersManager::checkIfLoginExists()
{
    string login;

    bool flag = false;

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        if (users.size() != 0)
        {
            for (unsigned int i = 0; i < users.size(); i++)
        {
            if (login != users[i].getLogin())
            {
                flag = true;
                
            } else 
            {
                flag = false; 
                cout << "Taki login istnieje. Podaj inny." << endl; 
                break; 
            }
        }
        } else 
        {
            flag = true; 
        }
        
    } while (flag == false); 

    return login; 
}

int UsersManager::addUsersId()
{

    if(users.size() != 0)
    {
        idOfLastUser = users.back().getUserId() + 1; 
    } else
    {
        idOfLastUser++; 
    }
    
    return idOfLastUser; 
}
int UsersManager::getIdOfLoggedUser()
{
    return idOfLoggedUser; 
}
void UsersManager::setIdOfLoggedUser(int id_of_logged_user)
{
    idOfLoggedUser = id_of_logged_user; 
}