#ifndef AUXILIARYFUNCTIONS_H
#define AUXILIARYFUNCTIONS_H
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "Users.h"

using namespace std;

class AuxiliaryFunctions
{
public:
    static char loadCharacter();
    static string currentDate();
    static bool checkDate(string date);
    static string prepareToSaveToFile(double amount);
    static string addHyphenToDate(string date);
    static map<string, string> daysOfMonth(); 
    static string minusOneMonth(string date);
};

#endif