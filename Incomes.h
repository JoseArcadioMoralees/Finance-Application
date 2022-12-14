#ifndef INCOMES_H
#define INCOMES_H
#include<iostream>

using namespace std; 

class Incomes
{
    int incomeId, amount; 
    string date, item; 

public: 
    int getIncomeId();
    int getAmount();
    string getDate();
    string getItem();

    void setIncomeId(int INCOMEID);
    void setAmount(int AMOUNT);
    void setDate(string DATE);
    void setItem(string ITEM); 
};



#endif