#include <iostream>
#include "Markup.h"
#include "Users.h"
#include "UsersFile.h"
#include "UsersManager.h"
#include <string>
#include <vector>


using namespace std;

int main()
{ 
  UsersManager usersManager; 
  usersManager.registerNewUser(); 
  return 0;
}