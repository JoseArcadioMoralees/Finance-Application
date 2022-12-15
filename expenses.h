#ifndef EXPENSES_H
#define EXPENSES_H
#include<iostream>

using namespace std; 

class Expenses
{
    int expenseId, userId, amount; 
    string date, item; 

public: 
    int getUserId(); 
    int getExpenseId();
    int getAmount();
    string getDate();
    string getItem();

    void setUserId(int USERID);
    void setExpenseId(int INCOMEID);
    void setAmount(int AMOUNT); 
    void setDate(string DATE);
    void setItem(string ITEM); 
};



#endif