#include "FinanceApplication.h"

void FinanceApplication::registerNewUser()
{
    usersManager.registerNewUser();
}

void FinanceApplication::logAUser()
{
    usersManager.logAUser();
    idOfLoggedUser  = usersManager.getIdOfLoggedUser(); 
    financialManager = new FinancialManager(idOfLoggedUser); 
}

void FinanceApplication::showUsers()
{
    usersManager.showUsers();
}

int FinanceApplication::getIdOfLoggedUser()
{
    return usersManager.getIdOfLoggedUser(); 
}
void FinanceApplication::logOut()
{
    usersManager.setIdOfLoggedUser(0); 
    delete financialManager;
    financialManager = NULL;
}

void FinanceApplication::addIncome()
{
    financialManager->addIncome(); 
}

void FinanceApplication::addExpense()
{
    financialManager->addExpense(); 
}

void FinanceApplication::balance()
{
    financialManager->balance(); 
}