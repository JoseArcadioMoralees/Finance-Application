#include <iostream>
#include "Markup.h"
#include "Users.h"
#include "UsersFile.h"
#include <string>
#include <vector>


using namespace std;

int main()
{
  UsersFile::loadFromFile(); 

  return 0;
}