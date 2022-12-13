#include <iostream>
#include "Markup.h"
#include "Users.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
  CMarkup xml;
  int nQty = 12;
  string strSN = "brak danych";

  bool fileExists = xml.Load("Sample.xml");

  if (fileExists)
  {
    cout << "loaded" << endl;
  }
  else
    cout << "ERROR" << endl;

  if (fileExists)
  {
    xml.FindElem(); 
    xml.IntoElem(); // inside ORDER
    xml.FindElem("ORDER");
    xml.IntoElem();
    strSN = xml.GetData();
    xml.ResetPos();
    xml.FindElem("QTY");
    nQty = atoi(MCD_2PCSZ(xml.GetData()));
    xml.OutOfElem();
  }

  cout << "nQty: " << nQty << endl;
  cout << "strSN: " << strSN << endl;

  return 0;
}