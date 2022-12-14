#include "Incomes.h"

int Incomes::getIncomeId()
{
    return incomeId; 
}
int Incomes::getAmount()
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

void Incomes::setIncomeId(int INCOMEID)
{
    incomeId = INCOMEID; 
}
void Incomes::setAmount(int AMOUNT)
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