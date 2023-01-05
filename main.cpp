#include <iostream>
#include "UsersManager.h"
#include "FinancialManager.h"
#include "AuxiliaryFunctions.h"
#include <string>
#include <vector>


using namespace std;

int main()
{


  system("cls");
  
  FinancialManager financialManager;   
 // financialManager.addExpense();
  // financialManager.addIncome();
  // financialManager.addIncome();
  // financialManager.addIncome();  
  financialManager.addExpense();
  financialManager.addExpense();
  financialManager.addExpense();  
  financialManager.loadExpense();  


  /*
  while (true)
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
      usersManager.registerNewUser();
      break;
    case '2':
      usersManager.logAUser();
      break;
    case '9':
      exit(0);
      break;
    default:
      cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
      system("pause");
      break;
    }
  }

  */
  
  return 0;
}