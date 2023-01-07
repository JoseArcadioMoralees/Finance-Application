#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER_H
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <iomanip>
#include <map>
#include "ExpensesFile.h"
#include "IncomesFile.h"
#include "AuxiliaryFunctions.h"


class FinancialManager
{
    const int ID_OF_LOGGED_USER; 

    IncomesFile incomesFile;  
    ExpensesFile expensesFile; 
    string getDate();
    int getIdOfLastIncome(); 
    int getIdOfLastExpense();
    void totalBalance();
    void periodBalance();  
    void currentMonthBalance();
    void lastMonthBalance();
    void loadIncome(); 
    void loadExpense(); 
    map<string, string>DaysOfMonth; 
    void daysOfMonth(); 
    string minusOneMonth(string date);
    
    

public:
    FinancialManager(int id_of_logged_user): ID_OF_LOGGED_USER(id_of_logged_user) {}

    void addIncome(); 
    void addExpense(); 
    void balance(); 
     
    
    
};


#endif