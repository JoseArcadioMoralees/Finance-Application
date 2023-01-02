#ifndef AUXILIARYFUNCTIONS_H
#define AUXILIARYFUNCTIONS_H
#include<iostream>
#include <ctime>
#include<vector>
#include <string> 
#include "Users.h"

using namespace std; 

class AuxiliaryFunctions
{
public: 
    static char loadCharacter();
    static bool checkLogin(string login, vector<Users> users);
    static string currentDate();
    static bool checkDate(string date);  
};



#endif