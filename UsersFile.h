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
    void saveToFile(vector<Users> users); 
    void loadFromFile();
};

#endif