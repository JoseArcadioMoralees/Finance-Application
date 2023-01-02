#include "AuxiliaryFunctions.h"


char AuxiliaryFunctions::loadCharacter()
{
    cin.clear();
    string entry = "";
    char character  = {0};
    while (true)
    { 
        cin.sync();
        getline(cin, entry);
        if (entry.length() == 1)
        {
            character = entry[0];
            cin.clear();
            break;
        } else
        {
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
        }
    }
    return character;
}

bool AuxiliaryFunctions::checkLogin(string login, vector<Users> users)
{
    for(unsigned int i = 0; i < users.size(); i++)
    {
        if (login == users[i].getLogin())
        {
            return true;
            break; 
        } else if (login != users[i].getLogin() && i == (users.size() -1))
        {
            return false; 
            break; 
        }
    }
}

string AuxiliaryFunctions::currentDateTime()
{
    string date, year, month, day; 
    int zero = 0; 

    time_t now = time(0);

    tm *ltm = localtime(&now);
    year = to_string(1900 + ltm->tm_year); 

    if (1 + ltm->tm_mon >=10)
    {
        month = to_string(1 + ltm->tm_mon);
    } else
    {
        month = to_string(zero) + to_string(1 + ltm->tm_mon); 
    }
    
    if (ltm->tm_mday >=10)
    {
        day = to_string(ltm->tm_mday); 
    } else
    {
        day = to_string(zero) + to_string(ltm->tm_mday); 
    } 
    cout << "year: " << year << endl;
    cout << "month: " << month << endl;
    cout << "day: " << day << endl;

    date = year + month + day;

    return date; 


}