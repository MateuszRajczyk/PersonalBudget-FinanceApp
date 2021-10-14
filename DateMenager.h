#ifndef DATEMENAGER_H
#define DATEMENAGER_H

#include <iostream>
#include "Income.h"
#include "Expense.h"
#include "SupplementaryMethods.h"
#include <windows.h>


using namespace std;

class DateMenager
{

public:
    string setDateInCorrectFormat(string date);
    bool isDateCorrect(string date);
    int numbersOfDaysInMonth(int month, int year);
    bool isLeapYear(int year);
    int convertDateIntoNumber(string date);
};

#endif
