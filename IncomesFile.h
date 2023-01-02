#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include<iostream>
#include "Markup.h"
#include "Incomes.h"
#include<vector>
#include<algorithm>

class IncomesFile
{
public:
    void saveToFile(Incomes income); 
    vector<Incomes> LoadFromFile(); 
};


#endif