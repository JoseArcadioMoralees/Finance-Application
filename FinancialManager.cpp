#include "FinancialManager.h"

void FinancialManager::addIncome()
{
    Incomes income;
    income.setUserId(ID_OF_LOGGED_USER);

    income.setIncomeId(incomesFile.getIdOfLastIncome());
    incomesFile.setIdOfLastIncome(income.getIncomeId()); 


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

    incomes.push_back(income); 
    incomesFile.saveToFile(income);

    sort(incomes.begin(), incomes.end(), Incomes::compareDates);

    cout << "Dodano przychod" << endl;
    system("Pause"); 
}

void FinancialManager::addExpense()
{
    Expenses expense;
    expense.setUserId(ID_OF_LOGGED_USER);

    expense.setExpenseId(expensesFile.getIdOfLastExpense());
    expensesFile.setIdOfLastExpense(expense.getExpenseId()); 

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

    expenses.push_back(expense);
    expensesFile.saveToFile(expense);
    sort(expenses.begin(), expenses.end(), Expenses::compareDates);

    cout << "Dodano wydatek" << endl;
    system("Pause");
}

void FinancialManager::totalBalance()
{
    double sumOfExpenses = 0;
    double sumOfIncomes = 0;
    double balance;

    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        sumOfIncomes += incomes[i].getAmount();
    }

    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        sumOfExpenses += expenses[i].getAmount();
    }

    balance = sumOfIncomes - sumOfExpenses;

    cout << endl
         << "Przychody" << endl;
    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        cout << "Rodzaj: " << incomes[i].getItem() << " | "
             << "Kwota: " << fixed << setprecision(2) << incomes[i].getAmount() << " | "
             << "Data: " << incomes[i].getDate() << endl;
    }
    cout << endl
         << endl;

    cout << "Wydatki" << endl;
    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        cout << "Rodzaj: " << expenses[i].getItem() << " | "
             << "Kwota: " << fixed << setprecision(2) << expenses[i].getAmount() << " | "
             << "Data: " << expenses[i].getDate() << endl;
    }
    cout << endl;

    cout << "Suma przychodow: " << fixed << setprecision(2) << sumOfIncomes << endl;
    cout << "Suma wydatkow: " << fixed << setprecision(2) << sumOfExpenses << endl;
    cout << "Bilans: " << balance << endl;
    system("Pause");
}

void FinancialManager::periodBalance()
{
    double sumOfExpenses = 0;
    double sumOfIncomes = 0;
    double balance;
    string startDate, endDate;

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
                 << "Kwota: " << fixed << setprecision(2) << incomes[i].getAmount() << " | "
                 << "Data: " << incomes[i].getDate() << endl;
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
                 << "Kwota: " << fixed << setprecision(2) << expenses[i].getAmount() << " | "
                 << "Data: " << expenses[i].getDate() << endl;
        }
    }
    cout << endl
         << endl;

    cout << "Suma przychodow: " << fixed << setprecision(2) << sumOfIncomes << endl;
    cout << "Suma wydatkow: " << fixed << setprecision(2) << sumOfExpenses << endl;
    cout << "Bilans: " << balance << endl;

    system("Pause");
}

void FinancialManager::currentMonthBalance()
{
    double sumOfExpenses = 0;
    double sumOfIncomes = 0;
    double balance;
    string startDate, endDate, daysOfMonth, currentDate, month;
    currentDate = AuxiliaryFunctions::currentDate();
    map<string, string> DaysOfMonth = AuxiliaryFunctions::daysOfMonth(); 

    month = currentDate[5];
    month = month + currentDate[6];
    for (map<string, string>::iterator itr = DaysOfMonth.begin(); itr != DaysOfMonth.end(); itr++)
    {
        if (month == itr->first)
        {
            daysOfMonth = itr->second;
        }
    }
    currentDate.replace(8, 2, "01");
    startDate = currentDate;
    currentDate.replace(8, 2, daysOfMonth);
    endDate = currentDate;

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
                 << "Kwota: " << fixed << setprecision(2) << incomes[i].getAmount() << " | "
                 << "Data: " << incomes[i].getDate() << endl;
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
                 << "Kwota: " << fixed << setprecision(2) << expenses[i].getAmount() << " | "
                 << "Data: " << expenses[i].getDate() << endl;
        }
    }
    cout << endl
         << endl;

    cout << "Suma przychodow: " << fixed << setprecision(2) << sumOfIncomes << endl;
    cout << "Suma wydatkow: " << fixed << setprecision(2) << sumOfExpenses << endl;
    cout << "Bilans: " << balance << endl;

    system("Pause");
}

void FinancialManager::lastMonthBalance()
{
    double sumOfExpenses = 0;
    double sumOfIncomes = 0;
    double balance;
    string startDate, endDate, daysOfMonth, currentDate, month;
    map<string, string> DaysOfMonth = AuxiliaryFunctions::daysOfMonth(); 

    currentDate = AuxiliaryFunctions::currentDate();
    currentDate = AuxiliaryFunctions::minusOneMonth(currentDate);

    month = currentDate[5];
    month = month + currentDate[6];
    for (map<string, string>::iterator itr = DaysOfMonth.begin(); itr != DaysOfMonth.end(); itr++)
    {
        if (month == itr->first)
        {
            daysOfMonth = itr->second;
        }
    }
    currentDate.replace(8, 2, "01");
    startDate = currentDate;
    currentDate.replace(8, 2, daysOfMonth);
    endDate = currentDate;

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
                 << "Kwota: " << fixed << setprecision(2) << incomes[i].getAmount() << " | "
                 << "Data: " << incomes[i].getDate() << endl;
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
                 << "Kwota: " << fixed << setprecision(2) << expenses[i].getAmount() << " | "
                 << "Data: " << expenses[i].getDate() << endl;
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
    cout << "Jaki bilans chcesz przeprowadzic?" << endl;
    cout << "1. Calkowity." << endl;
    cout << "2. Z wybranego okresu." << endl;
    cout << "3. Z obecnego miesiaca." << endl;
    cout << "4. Z poprzedniego miesiaca." << endl;
    cin >> option;

    switch (option)
    {
    case '1':
        totalBalance();
        break;
    case '2':
        periodBalance();
        break;
    case '3':
        currentMonthBalance();
        break;
    case '4':
        lastMonthBalance();
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
    int idOfLastIncome = 0;
    incomes = incomesFile.loadFromFile(ID_OF_LOGGED_USER);

    for (unsigned int i = 0; i < incomes.size(); i++)
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
    int idOfLastExpense = 0;
    expenses = expensesFile.loadFromFile(ID_OF_LOGGED_USER);

    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        if (idOfLastExpense < expenses[i].getExpenseId())
        {
            idOfLastExpense = expenses[i].getExpenseId();
        }
    }

    return ++idOfLastExpense;
}
