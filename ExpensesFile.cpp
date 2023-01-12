#include "ExpensesFile.h"

void ExpensesFile::saveToFile(Expenses expense)
{

    bool fileExists = xml.Load("expenses.xml");

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("expense");
    xml.IntoElem();
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("expensesId", expense.getExpenseId());
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", AuxiliaryFunctions::prepareToSaveToFile(expense.getAmount()));
    xml.AddElem("date", expense.getDate());

    xml.Save("expenses.xml");
}

vector<Expenses> ExpensesFile::loadFromFile(int ID_OF_LOGGED_USER)
{
    Expenses expense;
    vector<Expenses> expenses;

    if (xml.Load("expenses.xml"))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("expense"))
        {
            xml.IntoElem();

            xml.FindElem("userId");
            if (atoi(xml.GetData().c_str()) == ID_OF_LOGGED_USER)
            {
                expense.setUserId(atoi(xml.GetData().c_str()));
                xml.FindElem("expensesId");
                expense.setExpenseId(atoi(xml.GetData().c_str()));
                xml.FindElem("item");
                expense.setItem(xml.GetData());
                xml.FindElem("amount");
                expense.setAmount(stod(xml.GetData()));
                xml.FindElem("date");
                string date = xml.GetData();
                expense.setDate(date);

                xml.OutOfElem();

                expenses.push_back(expense);
            }
            else
            {
                xml.OutOfElem();
            }
        }
    }
    sort(expenses.begin(), expenses.end(), Expenses::compareDates);

    return expenses;
}

int ExpensesFile::loadIdOfLastExpenseFromFile()
{
    idOfLastExpense = 0;
    if (xml.Load("expenses.xml"))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("expense"))
        {
            xml.IntoElem();
            xml.FindElem("expensesId");
            idOfLastExpense = (stoi(xml.GetData()));
            xml.OutOfElem();
        }
    }
    return ++idOfLastExpense;
}

int ExpensesFile::getIdOfLastExpense()
{
    return idOfLastExpense;
}

void ExpensesFile::setIdOfLastExpense(int id_of_last_expense)
{
    idOfLastExpense = ++id_of_last_expense;
}