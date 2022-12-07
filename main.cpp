#include <iostream>
#include "Markup.h"

using namespace std;

int main()
{

    CMarkup abc;

    bool fileExists = abc.Load("people.xml");

    if (!fileExists)
    {
        abc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        abc.AddElem("people");
    }

    abc.FindElem();
    abc.IntoElem();
    abc.AddElem("User");
  //  abc.FindElem();
    abc.IntoElem();
    abc.AddElem("UserId", "3");
    abc.OutOfElem(); 
    abc.AddElem("Login", "zofia");
    abc.IntoElem();
    abc.AddElem("Password", "ronald");

    abc.Save("people.xml");

    return 0;
}