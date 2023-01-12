#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include<iostream>
#include "Markup.h"
#include "Expenses.h"
#include "AuxiliaryFunctions.h"
#include<vector>
#include<algorithm>

class ExpensesFile
{
    CMarkup xml;
    
public:
    void saveToFile(Expenses expense); 
    vector<Expenses> LoadFromFile(int ID_OF_LOGGED_USER); 
};


#endif