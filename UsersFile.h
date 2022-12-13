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
    static vector<Users> users;
    static void saveToFile(); 
    static void loadFromFile();
};

#endif