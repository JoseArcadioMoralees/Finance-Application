#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include <iostream>
#include "Markup.h"
#include "Expenses.h"
#include "AuxiliaryFunctions.h"
#include <vector>
#include <algorithm>

class ExpensesFile
{
    CMarkup xml;
    int idOfLastExpense;
    int loadIdOfLastExpenseFromFile();

public:
    ExpensesFile()
    {
        idOfLastExpense = loadIdOfLastExpenseFromFile();
    }

    void saveToFile(Expenses expense);
    vector<Expenses> LoadFromFile(int ID_OF_LOGGED_USER);
    int getIdOfLastExpense();
    void setIdOfLastExpense(int id_of_last_expense);
};

#endif