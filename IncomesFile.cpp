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
    xml.AddElem("userId");
    xml.SetAttrib("value", income.getUserId());
    xml.IntoElem();
    xml.AddElem("incomesId", income.getIncomeId());
    xml.IntoElem();
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", income.getAmount());
    xml.AddElem("date", income.getDate());

    xml.Save("incomes.xml");
}

Incomes IncomesFile::LoadFromFile()
{
    CMarkup xml;
    Incomes income;

    if (xml.Load("incomes.xml"))
    {
        xml.FindElem();
        xml.IntoElem();

        
        xml.FindElem("userId");
        income.setUserId = xml.GetAttrib("value"); 
        xml.IntoElem();
        xml.FindElem("incomesId");
        xml.IntoElem();
        income.setIncomeId(atoi(xml.GetData().c_str())); 
        xml.FindElem("item");
        income.setItem(xml.GetData());
        xml.FindElem("amount");
        income.setAmount(atoi(xml.GetData().c_str()));
        xml.FindElem("date");
        income.setDate(xml.GetData());

    }

    cout << "User ID: " << income.getUserId() << endl; 
    cout << "Incomes ID: " << income.getIncomeId() << endl; 
    cout << "Item: " << income.getItem() << endl; 
    cout << "Amount: " << income.getAmount() << endl; 
    cout << "Date: " << income.getDate() << endl; 


    return income;
}