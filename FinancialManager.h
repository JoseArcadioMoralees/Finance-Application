#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER_H
#include<iostream>
#include "ExpensesFile.h"
#include "IncomesFile.h"


class FinancialManager
{
    IncomesFile incomesFile;  
    ExpensesFile expensesFile; 

public:
    void addIncome(); 
    void loadIncome(); 
    void addExpense(); 
    void loadExpense();
};


#endif