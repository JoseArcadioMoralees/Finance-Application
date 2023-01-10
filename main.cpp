#include <iostream>
#include "FinanceApplication.h"

using namespace std;

int main()
{

  FinanceApplication financeApplication;

  system("cls");

  while (true)
  {
    if (financeApplication.getIdOfLoggedUser() == 0)
    {
      char sign;
      system("cls");
      cout << "    >>> MENU  GLOWNE <<<" << endl;
      cout << "---------------------------" << endl;
      cout << "1. Rejestracja" << endl;
      cout << "2. Logowanie" << endl;
      cout << "9. Koniec programu" << endl;
      cout << "---------------------------" << endl;
      cout << "Twoj wybor: ";
      sign = AuxiliaryFunctions::loadCharacter();

      switch (sign)
      {
      case '1':
        financeApplication.registerNewUser();
        break;
      case '2':
        financeApplication.logAUser();
        break;
      case '9':
        exit(0);
        break;
      default:
        cout << endl
             << "Nie ma takiej opcji w menu." << endl
             << endl;
        system("pause");
        break;
      }
    }
    else
    {
      char sign;
      system("cls");
      cout << "    >>> FINANSE <<<" << endl;
      cout << "---------------------------" << endl;
      cout << "1. Dodaj przychod" << endl;
      cout << "2. Dodaj wydatek" << endl;
      cout << "3. Bilans" << endl;
      cout << "4. Zmiana hasla" << endl;
      cout << "5. Wyloguj sie" << endl;
      cout << "---------------------------" << endl;
      cout << "Twoj wybor: ";
      sign = AuxiliaryFunctions::loadCharacter();

      switch (sign)
      {
      case '1':
        financeApplication.addIncome();
        break;
      case '2':
        financeApplication.addExpense();
        break;
      case '3':
        financeApplication.balance();
        break;
      case '4':
        financeApplication.changePassword();
        break;
      case '5':
        financeApplication.logOut();
        break;
      default:
        cout << endl
             << "Nie ma takiej opcji w menu." << endl
             << endl;
        system("pause");
        break;
      }
    }
  }

  return 0;
}