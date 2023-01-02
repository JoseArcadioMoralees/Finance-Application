#include "IncomesFile.h"

void IncomesFile::saveToFile(Incomes income)
{
    CMarkup xml;

    bool fileExists = xml.Load("incomes.xml");

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("income");
    xml.IntoElem();
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("incomesId", income.getIncomeId());
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", income.getAmount());
    xml.AddElem("date", income.getDate());

    xml.Save("incomes.xml");
}

vector<Incomes> IncomesFile::LoadFromFile()
{
    CMarkup xml;
    Incomes income;
    vector<Incomes> incomes;

    if (xml.Load("incomes.xml"))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("income"))
        {
            xml.IntoElem();

            xml.FindElem("userId");
            income.setUserId(atoi(xml.GetData().c_str()));
            xml.FindElem("incomesId");
            income.setIncomeId(atoi(xml.GetData().c_str()));
            xml.FindElem("item");
            income.setItem(xml.GetData());
            xml.FindElem("amount");
            income.setAmount(atoi(xml.GetData().c_str()));
            xml.FindElem("date");
            string date = xml.GetData();
            date.erase(remove(date.begin(), date.end(), '-'), date.end());
            income.setDate(date);

            xml.OutOfElem();

            incomes.push_back(income);
        }
    }

    for (unsigned int i = 0; i < incomes.size(); i++)
    {
        cout << "User ID: " << incomes[i].getUserId() << endl;
        cout << "Incomes ID: " << incomes[i].getIncomeId() << endl;
        cout << "Item: " << incomes[i].getItem() << endl;
        cout << "Amount: " << incomes[i].getAmount() << endl;
        cout << "Date: " << incomes[i].getDate() << endl << endl; 
    }
    return incomes;
}