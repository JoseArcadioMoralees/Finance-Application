#include "ExpensesFile.h"

void ExpensesFile::saveToFile(Expenses expense)
{
    CMarkup xml;

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

vector<Expenses> ExpensesFile::LoadFromFile()
{
    CMarkup xml;
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
            expense.setUserId(atoi(xml.GetData().c_str()));
            xml.FindElem("expensesId");
            expense.setExpenseId(atoi(xml.GetData().c_str()));
            xml.FindElem("item");
            expense.setItem(xml.GetData());
            xml.FindElem("amount");
            expense.setAmount(atoi(xml.GetData().c_str()));
            xml.FindElem("date");
            string date = xml.GetData();
            date.erase(remove(date.begin(), date.end(), '-'), date.end());
            expense.setDate(date);
            xml.OutOfElem();

            expenses.push_back(expense);
        }
    }

    for (unsigned int i = 0; i < expenses.size(); i++)
    {
        cout << "User ID: " << expenses[i].getUserId() << endl;
        cout << "Expenses ID: " << expenses[i].getExpenseId() << endl;
        cout << "Item: " << expenses[i].getItem() << endl;
        cout << "Amount: " << expenses[i].getAmount() << endl;
        cout << "Date: " << expenses[i].getDate() << endl << endl; 
    }
    return expenses;
}