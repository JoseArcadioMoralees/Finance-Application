#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include<iostream>
#include "Markup.h"
#include "Incomes.h"

class IncomesFile
{
public:
    void saveToFile(Incomes income); 
    Incomes LoadFromFile(); 
};


#endif