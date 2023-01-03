#ifndef INCOMES_H
#define INCOMES_H
#include<iostream>

using namespace std; 

class Incomes
{
    int incomeId, userId; 
    double amount; 
    string date, item; 

public: 
    int getUserId(); 
    int getIncomeId();
    double getAmount();
    string getDate();
    string getItem();

    void setUserId(int USERID);
    void setIncomeId(int INCOMEID);
    void setAmount(double AMOUNT); 
    void setDate(string DATE);
    void setItem(string ITEM); 
};



#endif