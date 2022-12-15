#ifndef INCOMES_H
#define INCOMES_H
#include<iostream>

using namespace std; 

class Incomes
{
    int incomeId, userId, amount; 
    string date, item; 

public: 
    int getUserId(); 
    int getIncomeId();
    int getAmount();
    string getDate();
    string getItem();

    void setUserId(int USERID);
    void setIncomeId(int INCOMEID);
    void setAmount(int AMOUNT); 
    void setDate(string DATE);
    void setItem(string ITEM); 
};



#endif