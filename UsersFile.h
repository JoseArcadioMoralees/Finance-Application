#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <vector>
#include "Users.h"
#include "Markup.h"

using namespace std;

class UsersFile
{
    CMarkup xml;

public:
    void saveToFile(Users user);
    vector<Users> loadFromFile();
};

#endif