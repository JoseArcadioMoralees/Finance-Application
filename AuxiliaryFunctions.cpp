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

string AuxiliaryFunctions::currentDate()
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

    date = year + '-' + month + '-' + day;

    return date; 


}

bool AuxiliaryFunctions::checkDate(string date)
{
    if(date[4] != '-' || date[7] != '-')
    {
        cout << "Bledny zapis myslnikow (-) w dacie. Sprobuj ponownie." << endl;
        return false;  
    } else if((date[5] == '0' && 
    (date[6] == '1' || date[6] == '3' || date[6] == '5' || date[6] == '7' || date[6] == '8'))&&
    (date[8] >= '3' && date[9] > '1' ))
    {
        cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl; 
        return false;
    } else if((date[5] == '0' && 
    (date[6] == '4' || date[6] == '6' || date[6] == '9'))&&
    (date[8] >= '3' && date[9] > '0' ))
    {
        cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl; 
        return false;
    } else if((date[5] == '0' && 
    (date[6] == '2' ))&&
    (date[8] >= '2' && date[9] > '8' ))
    {
        cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl; 
        return false;
    } else if((date[5] == '1' && 
    (date[6] == '0' ))&&
    (date[8] >= '3' && date[9] > '1' ))
    {
        cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl; 
        return false;
    } else if((date[5] == '1' && 
    (date[6] == '1' ))&&
    (date[8] >= '3' && date[9] > '0' ))
    {
        cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl; 
        return false;
    } else if((date[5] == '1' && 
    (date[6] == '2' ))&&
    (date[8] >= '3' && date[9] > '1' ))
    {
        cout << "Ten miesiac nie ma tylu dni. Sprobuj ponownie." << endl; 
        return false;
    } 
    
    else 
    {
        return true; 
    }

}