#ifndef USERS_H
#define USERS_H
#include <iostream>

using namespace std;

class Users
{
    int userId;
    string login, password, name, surname;

public:
    int getUserId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();

    void setUserId(int);
    void setLogin(string);
    void setPassword(string);
    void setName(string);
    void setSurname(string);
};

#endif