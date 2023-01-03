#include "Incomes.h"

int Incomes::getUserId()
{
    return userId; 
}
int Incomes::getIncomeId()
{
    return incomeId; 
}
double Incomes::getAmount()
{
    return amount; 
}
string Incomes::getDate()
{
    return date; 
}
string Incomes::getItem()
{
    return item; 
}
void Incomes::setUserId(int USERID)
{
    userId = USERID;
}
void Incomes::setIncomeId(int INCOMEID)
{
    incomeId = INCOMEID; 
}
void Incomes::setAmount(double AMOUNT)
{
    amount = AMOUNT; 
}
void Incomes::setDate(string DATE)
{
    date = DATE; 
}
void Incomes::setItem(string ITEM)
{
    item = ITEM; 
}