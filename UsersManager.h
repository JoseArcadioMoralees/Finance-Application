#ifndef USERSMANAGER_H
#define USERSMANAGER_H
#include<iostream>
#include "UsersFile.h"
#include "AuxiliaryFunctions.h"


using namespace std; 

class UsersManager
{
    vector<Users> users; 
    UsersFile usersFile; 
public:
    void registerNewUser();
    void logAUser(); 
    void showUsers(); 
};
#endif