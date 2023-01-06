#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include<iostream>
#include "Markup.h"
#include "Incomes.h"
#include "AuxiliaryFunctions.h"
#include<vector>
#include<algorithm>
#include <string>

class IncomesFile
{
public:

    void saveToFile(Incomes income); 
    vector<Incomes> LoadFromFile(int ID_OF_LOGGED_USER); 
};


#endif