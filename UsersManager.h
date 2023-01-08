#ifndef USERSMANAGER_H
#define USERSMANAGER_H
#include<iostream>
#include <cstdio>
#include "UsersFile.h"
#include "AuxiliaryFunctions.h"


using namespace std; 

class UsersManager
{
    string usersLogin;
    string usersPassword; 
    int idOfLoggedUser; 
    int idOfLastUser; 
    vector<Users> users = usersFile.loadFromFile(); 
    UsersFile usersFile; 
    bool checkLogin(string login, vector<Users> users);
    bool checkPassword(string password, vector<Users> users); 
    string checkIfLoginExists(); 
    int addUsersId(); 

public:
    UsersManager()
    {
        idOfLastUser = 0; 
        idOfLoggedUser = 0; 
    }

    void registerNewUser();
    void logAUser(); 
    void showUsers(); 
    int getIdOfLoggedUser(); 
    void setIdOfLoggedUser(int id_of_logged_user); 
    void changePassword(); 
};
#endif