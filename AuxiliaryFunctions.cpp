#include "AuxiliaryFunctions.h"

char AuxiliaryFunctions::loadCharacter()
{
    cin.clear();
    string entry = "";
    char character = {0};
    while (true)
    {
        cin.sync();
        getline(cin, entry);
        if (entry.length() == 1)
        {
            character = entry[0];
            cin.clear();
            break;
        }
        else
        {
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
        }
    }
    return character;
}

string AuxiliaryFunctions::currentDate()
{
    string date, year, month, day;
    int zero = 0;

    time_t now = time(0);

    tm *ltm = localtime(&now);
    year = to_string(1900 + ltm->tm_year);

    if (1 + ltm->tm_mon >= 10)
    {
        month = to_string(1 + ltm->tm_mon);
    }
    else
    {
        month = to_string(zero) + to_string(1 + ltm->tm_mon);
    }

    if (ltm->tm_mday >= 10)
    {
        day = to_string(ltm->tm_mday);
    }
    else
    {
        day = to_string(zero) + to_string(ltm->tm_mday);
    }

    date = year + '-' + month + '-' + day;

    return date;
}

bool AuxiliaryFunctions::checkDate(string date)
{
    bool flag = true;
    string dateWithoutHyphens = date;
    dateWithoutHyphens.erase(4, 1);
    dateWithoutHyphens.erase(6, 1);
    string lastPossibleDate = AuxiliaryFunctions::currentDate();
    lastPossibleDate.replace(8, 2, "31");

    for (unsigned int i = 0; i < dateWithoutHyphens.size(); i++)
    {
        if (dateWithoutHyphens[i] < 44 || dateWithoutHyphens[i] > 57)
        {
            cout << "W ktoryms miejscu wpisano cos innego niz cyfry." << endl;
            flag = false;
            break;
        }
    }
    if (date.size() < 10)
    {
        cout << "Podano za mala ilosc znakow." << endl;
        flag = false;
    }
    if (date.size() > 10)
    {
        cout << "Podano za duza ilosc znakow." << endl;
        flag = false;
    }
    if (date[4] != '-' || date[7] != '-')
    {
        cout << "Bledny zapis myslnikow (-) w dacie. Sprobuj ponownie." << endl;
        flag = false;
    }
    if ((date[5] == '0' &&
         (date[6] == '1' || date[6] == '3' || date[6] == '5' || date[6] == '7' || date[6] == '8')) &&
        (date[8] >= '3' && date[9] > '1'))
    {
        cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl;
        flag = false;
    }
    if ((date[5] == '0' &&
         (date[6] == '4' || date[6] == '6' || date[6] == '9')) &&
        (date[8] >= '3' && date[9] > '0'))
    {
        cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl;
        flag = false;
    }
    if ((date[5] == '1' &&
         (date[6] == '0')) &&
        (date[8] >= '3' && date[9] > '1'))
    {
        cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl;
        flag = false;
    }
    if ((date[5] == '1' &&
         (date[6] == '1')) &&
        (date[8] >= '3' && date[9] > '0'))
    {
        cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl;
        flag = false;
    }
    if ((date[5] == '1' &&
         (date[6] == '2')) &&
        (date[8] >= '3' && date[9] > '1'))
    {
        cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl;
        flag = false;
    }
    if (dateWithoutHyphens < "20000101")
    {
        cout << "Data jest wczesniejsza niz 2000-01-01. Podaj pozniejsza date." << endl;
        flag = false;
    }
    if (date > lastPossibleDate)
    {
        cout << "Zbyt pozna data. Ostatnia mozliwa data to ostatni dzien biezacego miesiaca." << endl;
        flag = false;
    }
    dateWithoutHyphens = dateWithoutHyphens.erase(4, 4);
    int year = stoi(dateWithoutHyphens);

    if (year % 4 != 0)
    {
        if ((date[5] == '0' &&
             (date[6] == '2')) &&
            (date[8] >= '2' && date[9] > '8'))
        {
            cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl;
            flag = false;
        }
    }
    else
    {
        if ((date[5] == '0' &&
             (date[6] == '2')) &&
            (date[8] >= '2' && date[9] > '9'))
        {
            cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl;
            flag = false;
        }
    }

    return flag;
}

string AuxiliaryFunctions::prepareToSaveToFile(double amount)
{
    string amountStr = to_string(amount);
    size_t pos = amountStr.find(".");
    amountStr.erase(pos + 3, 10);
    return amountStr;
}

string AuxiliaryFunctions::addHyphenToDate(string date)
{
    date = date.insert(4, "-");
    date = date.insert(7, "-");
    return date;
}

map<string, string> AuxiliaryFunctions::daysOfMonth()
{
    map<string, string> DaysOfMonth;
    DaysOfMonth["01"] = "31";
    DaysOfMonth["02"] = "28";
    DaysOfMonth["03"] = "31";
    DaysOfMonth["04"] = "30";
    DaysOfMonth["05"] = "31";
    DaysOfMonth["06"] = "30";
    DaysOfMonth["07"] = "31";
    DaysOfMonth["08"] = "31";
    DaysOfMonth["09"] = "30";
    DaysOfMonth["10"] = "31";
    DaysOfMonth["11"] = "30";
    DaysOfMonth["12"] = "31";
    return DaysOfMonth; 
}

string AuxiliaryFunctions::minusOneMonth(string date)
{
    string month = "";
    string year = "";
    int tempMonth;
    int tempYear;

    if (date[5] != '0' || date[6] != '1')
    {
        month = date[5];
        month = month + date[6];
        tempMonth = stoi(month);
        tempMonth--;
        if (tempMonth < 10)
        {
            month = '0';
            month += to_string(tempMonth);
        }
        else
        {
            month = to_string(tempMonth);
        }
        date.replace(5, 2, month);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            year += date[i];
        }
        tempYear = stoi(year);
        tempYear--;

        year = to_string(tempYear);
        date.replace(5, 2, "12");
        date.replace(0, 4, year);
    }

    return date;
}


