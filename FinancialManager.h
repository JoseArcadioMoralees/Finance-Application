#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER_H
#include<iostream>
#include "ExpensesFile.h"
#include "IncomesFile.h"
#include "AuxiliaryFunctions.h"


class FinancialManager
{
    IncomesFile incomesFile;  
    ExpensesFile expensesFile; 
    string getDate();

public:
    void addIncome(); 
    void loadIncome(); 
    void addExpense(); 
    void loadExpense();
    void balance();
     
};


#endif