#include <iostream>
#include "Markup.h"
#include "Users.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
  string checker = "last printed element";
  CMarkup xml;
  int nQty;
  string strSN;

  // xml.AddElem("ORDER");
  // xml.IntoElem();
  // xml.AddElem("ITEM");
  // xml.IntoElem();
  // xml.AddElem("SN", "132487A-J");
  // xml.AddElem("NAME", "crank casing");
  // xml.AddElem("QTY", "1");

  // xml.Save("ORDER.xml");
  {
    xml.IntoElem();
    xml.FindElem("SN");
    strSN = xml.GetData();
    cout << strSN << endl;
    xml.ResetMainPos();
    xml.FindElem("QTY");
    nQty = atoi(MCD_2PCSZ(xml.GetData()));
    xml.OutOfElem();
  }
  

  return 0;
}