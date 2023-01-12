#include "IncomesFile.h"

void IncomesFile::saveToFile(Incomes income)
{
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
    xml.AddElem("amount", AuxiliaryFunctions::prepareToSaveToFile(income.getAmount()));
    xml.AddElem("date", income.getDate());

    xml.Save("incomes.xml");
}

vector<Incomes> IncomesFile::loadFromFile(int ID_OF_LOGGED_USER)
{
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
            if (atoi(xml.GetData().c_str()) == ID_OF_LOGGED_USER)
            {
                income.setUserId(atoi(xml.GetData().c_str()));
                xml.FindElem("incomesId");
                income.setIncomeId(atoi(xml.GetData().c_str()));
                xml.FindElem("item");
                income.setItem(xml.GetData());
                xml.FindElem("amount");
                income.setAmount(stod(xml.GetData()));
                xml.FindElem("date");
                string date = xml.GetData();
                income.setDate(date);

                xml.OutOfElem();

                incomes.push_back(income);
            }
            else
            {
                xml.OutOfElem();
            }
        }
    }
    sort(incomes.begin(), incomes.end(), Incomes::compareDates);

    return incomes;
}

int IncomesFile::loadIdOfLastIncomeFromFile()
{
    idOfLastIncome = 0;
    if (xml.Load("incomes.xml"))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("income"))
        {
            xml.IntoElem();
            xml.FindElem("incomesId");
            idOfLastIncome = (stoi(xml.GetData()));
            xml.OutOfElem();
        }
    }
    return ++idOfLastIncome;
}

int IncomesFile::getIdOfLastIncome()
{
    return idOfLastIncome;
}

void IncomesFile::setIdOfLastIncome(int id_of_last_income)
{
    idOfLastIncome = ++id_of_last_income;
}