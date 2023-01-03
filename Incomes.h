#ifndef INCOMES_H
#define INCOMES_H
#include<iostream>
#include<algorithm>

using namespace std; 

class Incomes
{
    int incomeId, userId; 
    double amount; 
    string date, item; 

public: 
    static bool compareDates(Incomes date1, Incomes date2)
    {
        return (date1.date < date2.date); 
    }

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