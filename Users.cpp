#include "Users.h"

int Users::getUserId()
{
    return userId;
}

string Users::getLogin()
{
    return login;
}

string Users::getPassword()
{
    return password;
}

string Users::getName()
{
    return name;
}

string Users::getSurname()
{
    return surname;
}

void Users::setUserId(int USERID)
{
    userId = USERID;
}

void Users::setLogin(string LOGIN)
{
    login = LOGIN;
}

void Users::setPassword(string PASSWORD)
{
    password = PASSWORD;
}

void Users::setName(string NAME)
{
    name = NAME;
}

void Users::setSurname(string SURNAME)
{
    surname = SURNAME;
}
