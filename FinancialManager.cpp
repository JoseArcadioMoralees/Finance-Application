#include "FinancialManager.h"

void FinancialManager::addIncome()
{
    Incomes income; 
    cout << "Podaj ID uzytkownika: "; 
    int userID; 
    cin >> userID; 
    income.setUserId(userID);

    cout <<"Podaj ID przychodu: ";
    int incomeId; 
    cin >> incomeId; 
    income.setIncomeId(incomeId);

    cout << "Podaj nazwe przychodu: "; 
    string item; 
    cin >> item; 
    income.setItem(item);

    cout << "Podaj kwote przychodu: ";
    int amount;
    cin >> amount; 
    income.setAmount(amount);

    cout << "Podaj date przychodu: "; 
    string date;
    cin >> date; 
    income.setDate(date);

    incomesFile.saveToFile(income); 
    
}