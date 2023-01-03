#ifndef EXPENSES_H
#define EXPENSES_H
#include<iostream>

using namespace std; 

class Expenses
{
    int expenseId, userId;
    double amount; 
    string date, item; 

public: 
    int getUserId(); 
    int getExpenseId();
    double getAmount();
    string getDate();
    string getItem();

    void setUserId(int USERID);
    void setExpenseId(int INCOMEID);
    void setAmount(double AMOUNT); 
    void setDate(string DATE);
    void setItem(string ITEM); 
};



#endif