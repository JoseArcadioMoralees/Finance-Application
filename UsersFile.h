#ifndef USERSFILE_H
#define USERSFILE_H
#include<iostream>
#include<vector>
#include "Users.h"
#include "Markup.h"

using namespace std;

class UsersFile
{

public: 
    void saveToFile(Users user); 
    vector<Users> loadFromFile();
    void removeElementFromFile(int idOfLoggedUser); 
};

#endif