#ifndef AUXILIARYFUNCTIONS_H
#define AUXILIARYFUNCTIONS_H
#include<iostream>
#include<vector>
#include "Users.h"

using namespace std; 

class AuxiliaryFunctions
{
public: 
    static char loadCharacter();
    static bool checkLogin(string login, vector<Users> users);
};



#endif