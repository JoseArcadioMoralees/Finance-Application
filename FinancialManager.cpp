#include "FinancialManager.h"

void FinancialManager::addIncome()
{
    Incomes income;
    income.setUserId(ID_OF_LOGGED_USER);

    income.setIncomeId(getIdOfLastIncome());

    cout << "Podaj nazwe przychodu: ";
    string item;
    cin.ignore(0, '\n');
    getline(cin, item); 
    income.setItem(item);

    cout << "Podaj kwote przychodu: ";
    string writtenAmount;
    cin >> writtenAmount;
    replace(writtenAmount.begin(), writtenAmount.end(), ',', '.');
    double amount = stod(writtenAmount);
    income.setAmount(amount);

    income.setDate(getDate());

    incomesFile.saveToFile(income);
}

void FinancialManager::loadIncome()
{
    incomesFile.LoadFromFile(ID_OF_LOGGED_USER);
}

void FinancialManager::addExpense()
{
    Expenses expense;
    expense.setUserId(ID_OF_LOGGED_USER);

    expense.setExpenseId(getIdOfLastExpense());

    cout << "Podaj nazwe wydatku: ";
    string item;
    cin.ignore(0, '\n');
    getline(cin, item);
    expense.setItem(item);

    cout << "Podaj kwote wydatku: ";
    string writtenAmount;
    cin >> writtenAmount;
    replace(writtenAmount.begin(), writtenAmount.end(), ',', '.');
    double amount = stod(writtenAmount);

    expense.setAmount(amount);

    expense.setDate(getDate());

    expensesFile.saveToFile(expense);
}

void FinancialManager::loadExpense()
{
    expensesFile.LoadFromFile(ID_OF_LOGGED_USER);
}

void FinancialManager::totalBalance()
{
    vector<Expenses> expenses;
    vector<Incomes> incomes;
    double sumOfExpenses = 0;
    double sumOfIncomes = 0;
    double balance;

    incomes = incomesFile.LoadFromFile(ID_OF_LOGGED_USER);
    expenses = expensesFile.LoadFromFile(ID_OF_LOGGED_USER);

    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        sumOfIncomes += incomes[i].getAmount();
    }

    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        sumOfExpenses += expenses[i].getAmount();
    }

    balance = sumOfIncomes - sumOfExpenses;

    cout << endl << "Przychody" << endl;
    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        cout << "Rodzaj: " << incomes[i].getItem() << " | "
             << "Kwota: " << incomes[i].getAmount() << " | "
             << "Data: " << AuxiliaryFunctions::addHyphenToDate(incomes[i].getDate()) << endl;
    }
    cout << endl
         << endl;

    cout << "Wydatki" << endl;
    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        cout << "Rodzaj: " << expenses[i].getItem() << " | "
             << "Kwota: " << expenses[i].getAmount() << " | "
             << "Data: " << AuxiliaryFunctions::addHyphenToDate(expenses[i].getDate()) << endl;
    }
    cout << endl; 

    cout << "Suma przychodow: " << fixed << setprecision(2) << sumOfIncomes << endl;
    cout << "Suma wydatkow: " << fixed << setprecision(2) << sumOfExpenses << endl;
    cout << "Bilans: " << balance << endl;
    system("Pause"); 
}

void FinancialManager::periodBalance()
{
    vector<Expenses> expenses;
    vector<Incomes> incomes;
    double sumOfExpenses = 0;
    double sumOfIncomes = 0;
    double balance;
    string startDate, endDate;
    incomes = incomesFile.LoadFromFile(ID_OF_LOGGED_USER);
    expenses = expensesFile.LoadFromFile(ID_OF_LOGGED_USER);

    cout << "Podaj date startowa (rrrr-mm-dd): ";
    cin >> startDate;
    cout << "Podaj date koncowa (rrrr-mm-dd): ";
    cin >> endDate;

    startDate.erase(remove(startDate.begin(), startDate.end(), '-'), startDate.end());
    endDate.erase(remove(endDate.begin(), endDate.end(), '-'), endDate.end());

    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getDate() >= startDate && incomes[i].getDate() <= endDate)
        {
            sumOfIncomes += incomes[i].getAmount();
        }
    }

    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getDate() >= startDate && expenses[i].getDate() <= endDate)
        {
            sumOfExpenses += expenses[i].getAmount();
        }
    }

    balance = sumOfIncomes - sumOfExpenses;

    cout << "Przychody" << endl;
    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getDate() >= startDate && incomes[i].getDate() <= endDate)
        {
            cout << "Rodzaj: " << incomes[i].getItem() << " | "
                 << "Kwota: " << incomes[i].getAmount() << " | "
                 << "Data: " << AuxiliaryFunctions::addHyphenToDate(incomes[i].getDate()) << endl;
        }
    }
    cout << endl
         << endl;

    cout << "Wydatki" << endl;
    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getDate() >= startDate && expenses[i].getDate() <= endDate)
        {
            cout << "Rodzaj: " << expenses[i].getItem() << " | "
                 << "Kwota: " << expenses[i].getAmount() << " | "
                 << "Data: " << AuxiliaryFunctions::addHyphenToDate(expenses[i].getDate()) << endl;
        }
    }
    cout << endl
         << endl;

    cout << "Suma przychodow: " << fixed << setprecision(2) << sumOfIncomes << endl;
    cout << "Suma wydatkow: " << fixed << setprecision(2) << sumOfExpenses << endl;
    cout << "Bilans: " << balance << endl;

    system("Pause");
}

void FinancialManager::balance()
{
    char option; 
    cout << "Jaki bilans chcesz przeprowadzic? Calkowity: - c; z wybranego okresu - w: ";
    cin >> option; 
    option = toupper(option); 

    switch (option)
    {
    case 'C':
        totalBalance(); 
        break;
    case 'W':
        periodBalance(); 
        break;
    }
}

string FinancialManager::getDate()
{
    string date;
    char option;
    cout << "Czy chcesz zapisac dane pod aktualna data (T/N)?" << endl;
    cin >> option;
    option = toupper(option);
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

int FinancialManager::getIdOfLastIncome()
{
    vector<Incomes> incomes;
    int idOfLastIncome = 0; 
    incomes = incomesFile.LoadFromFile(ID_OF_LOGGED_USER);

    for(unsigned int i = 0; i < incomes.size(); i++)
    {
        if (idOfLastIncome < incomes[i].getIncomeId())
        {
            idOfLastIncome = incomes[i].getIncomeId();
        }
    }

    return ++idOfLastIncome; 
}

int FinancialManager::getIdOfLastExpense()
{
    vector<Expenses> expenses;
    int idOfLastExpense = 0; 
    expenses = expensesFile.LoadFromFile(ID_OF_LOGGED_USER);

    for(unsigned int i = 0; i < expenses.size(); i++)
    {
        if (idOfLastExpense < expenses[i].getExpenseId())
        {
            idOfLastExpense = expenses[i].getExpenseId();
        }
    }

    return ++idOfLastExpense;
}