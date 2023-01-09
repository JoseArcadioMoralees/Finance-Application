#ifndef EXPENSES_H
#define EXPENSES_H
#include <iostream>

using namespace std;

class Expenses
{
    int expenseId, userId;
    double amount;
    string date, item;

public:
    static bool compareDates(Expenses date1, Expenses date2)
    {
        return (date1.date < date2.date);
    }
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