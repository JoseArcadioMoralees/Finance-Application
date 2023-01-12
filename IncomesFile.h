#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include "Markup.h"
#include "Incomes.h"
#include "AuxiliaryFunctions.h"
#include <vector>
#include <algorithm>
#include <string>

class IncomesFile
{
    CMarkup xml;
    int idOfLastIncome;
    int loadIdOfLastIncomeFromFile();

public:
    IncomesFile()
    {
        idOfLastIncome = loadIdOfLastIncomeFromFile();
    }
    void saveToFile(Incomes income);
    vector<Incomes> loadFromFile(int ID_OF_LOGGED_USER);
    int getIdOfLastIncome();
    void setIdOfLastIncome(int id_of_last_income);
};

#endif