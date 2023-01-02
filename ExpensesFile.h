#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include<iostream>
#include "Markup.h"
#include "Expenses.h"
#include<vector>
#include<algorithm>

class ExpensesFile
{
public:
    void saveToFile(Expenses expense); 
    vector<Expenses> LoadFromFile(); 
};


#endif