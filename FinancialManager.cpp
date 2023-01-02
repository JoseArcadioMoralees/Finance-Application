#include "FinancialManager.h"

void FinancialManager::addIncome()
{
    Incomes income;
    cout << "Podaj ID uzytkownika: ";
    int userID;
    cin >> userID;
    income.setUserId(userID);

    cout << "Podaj ID przychodu: ";
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

    income.setDate(getDate());

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

    cout << "Podaj ID wydatku: ";
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

    expense.setDate(getDate());

    expensesFile.saveToFile(expense);
}

void FinancialManager::loadExpense()
{
    expensesFile.LoadFromFile();
}

void FinancialManager::balance()
{
    vector<Expenses> expenses;
    vector<Incomes> incomes;
    int sumOfExpenses = 0;
    int sumOfIncomes = 0;
    int balance;

    expenses = expensesFile.LoadFromFile();
    incomes = incomesFile.LoadFromFile();

    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        sumOfIncomes += incomes[i].getAmount();
    }

    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        sumOfExpenses += expenses[i].getAmount();
    }

    balance = sumOfIncomes - sumOfExpenses;

    cout << "Balance: " << balance << endl;
}
string FinancialManager::getDate()
{
    string date;
    char option;
    cout << "Czy chcesz zapisac dane pod aktualna data (T/N)?" << endl;
    cin >> option;
    switch (option)
    {
    case 'T':
        date = AuxiliaryFunctions::currentDate();
        break;

    case 'N':
        do
        {
            cout << "Podaj date (rrrr-mm-dd): ";
            cin >> date;
        } while (AuxiliaryFunctions::checkDate(date) != true);
        break;
    }

    return date;
}