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

void FinancialManager::loadIncome()
{
    incomesFile.LoadFromFile(); 
}

void FinancialManager::addExpense()
{
    Expenses expense; 
    cout << "Podaj ID uzytkownika: "; 
    int userID; 
    cin >> userID; 
    expense.setUserId(userID);

    cout <<"Podaj ID wydatku: ";
    int expenseId; 
    cin >> expenseId; 
    expense.setExpenseId(expenseId);

    cout << "Podaj nazwe wydatku: "; 
    string item; 
    cin >> item; 
    expense.setItem(item);

    cout << "Podaj kwote wydatku: ";
    int amount;
    cin >> amount; 
    expense.setAmount(amount);

    cout << "Podaj date wydatku: "; 
    string date;
    cin >> date; 
    expense.setDate(date);

    expensesFile.saveToFile(expense); 
}

void FinancialManager::loadExpense()
{
    expensesFile.LoadFromFile();  
}