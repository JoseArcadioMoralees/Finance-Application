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
    xml.AddElem("userId", income.getUserId());
    xml.IntoElem();
    xml.AddElem("incomesId", income.getIncomeId());
    xml.IntoElem();
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", income.getAmount());
    xml.AddElem("date", income.getDate());


    xml.Save("incomes.xml");
}