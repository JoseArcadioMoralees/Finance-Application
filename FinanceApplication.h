#include <iostream>
#include "FinancialManager.h"
#include "UsersManager.h"


using namespace std; 

class FinanceApplication
{
    UsersManager usersManager;  
    int idOfLoggedUser = usersManager.getIdOfLoggedUser();  
    FinancialManager *financialManager;
public:
    FinanceApplication()
    {
        financialManager = NULL; 
    }

    ~FinanceApplication()
    {
        delete financialManager;
        financialManager = NULL; 
    }

    void registerNewUser();
    void logAUser(); 
    void showUsers();
    int getIdOfLoggedUser(); 
    void logOut(); 
    void addIncome();
    void addExpense();
    void balance();


};