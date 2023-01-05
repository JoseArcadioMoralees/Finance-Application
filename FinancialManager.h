#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER_H
#include<iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include "ExpensesFile.h"
#include "IncomesFile.h"
#include "AuxiliaryFunctions.h"


class FinancialManager
{
    int idOfLoggedUser; 

    IncomesFile incomesFile;  
    ExpensesFile expensesFile; 
    string getDate();
    int getIdOfLastIncome(); 
    int getIdOfLastExpense();
    void totalBalance();
    void periodBalance(); 
    

public:
    FinancialManager()
    {
        idOfLoggedUser = 1; 
    }

    void addIncome(); 
    void loadIncome(); 
    void addExpense(); 
    void loadExpense();
    void balance(); 
    
    
};


#endif