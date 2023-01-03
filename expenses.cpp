#include "Expenses.h"

int Expenses::getUserId()
{
    return userId; 
}
int Expenses::getExpenseId()
{
    return expenseId; 
}
double Expenses::getAmount()
{
    return amount; 
}
string Expenses::getDate()
{
    return date; 
}
string Expenses::getItem()
{
    return item; 
}
void Expenses::setUserId(int USERID)
{
    userId = USERID;
}
void Expenses::setExpenseId(int INCOMEID)
{
    expenseId = INCOMEID; 
}
void Expenses::setAmount(double AMOUNT)
{
    amount = AMOUNT; 
}
void Expenses::setDate(string DATE)
{
    date = DATE; 
}
void Expenses::setItem(string ITEM)
{
    item = ITEM; 
}