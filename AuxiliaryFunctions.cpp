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