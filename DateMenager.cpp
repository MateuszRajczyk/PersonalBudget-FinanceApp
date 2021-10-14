#include "DateMenager.h"

string DateMenager::setDateInCorrectFormat(string date)
{
    SupplementaryMethods supplementaryMethods;
    SYSTEMTIME st;
    GetSystemTime(&st);

    if((st.wMonth < 10) && (st.wDay < 10))
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wDay);
    }
    else if(st.wMonth < 10)
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + supplementaryMethods.conversionIntegerToString(st.wDay);
    }
    else if(st.wDay < 10)
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + "0" + supplementaryMethods.conversionIntegerToString(st.wDay);
    }
    else
    {
        date = supplementaryMethods.conversionIntegerToString(st.wYear) + "-" + supplementaryMethods.conversionIntegerToString(st.wMonth) + "-" + supplementaryMethods.conversionIntegerToString(st.wDay);
    }

    return date;
}

bool DateMenager::isDateCorrect(string date)
{
    SupplementaryMethods supplementaryMethods;
    SYSTEMTIME st;
    GetSystemTime(&st);

    string dateYear, dateMonth, dateDay;
    int checkDateYear, checkDateMonth, checkDateDay;

    for(int i = 0; i < date.length(); i++)
    {
        if((date[4] != '-') || (date[7] != '-'))
        {
            return false;
        }
        else if(i < 4)
        {
            dateYear += date[i];
        }
        else if((i > 4) && (i < 7))
        {
            dateMonth += date[i];
        }
        else if(i > 7)
        {
            dateDay += date[i];
        }
    }

    checkDateYear = supplementaryMethods.conversionStringToInteger(dateYear);
    checkDateMonth = supplementaryMethods.conversionStringToInteger(dateMonth);
    checkDateDay = supplementaryMethods.conversionStringToInteger(dateDay);

    if(((checkDateYear >= 2000) && (checkDateYear <= st.wYear)) && ((checkDateMonth >= 1) && (checkDateMonth <= 12)) && (numbersOfDaysInMonth(checkDateMonth, checkDateYear) >= checkDateDay))
    {
        if(checkDateYear == st.wYear)
        {
            if(checkDateMonth <= st.wMonth)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
}

int DateMenager::numbersOfDaysInMonth(int month, int year)
{
    switch(month)
    {
    case 1:
        return 31;
        break;
    case 2:
        if(isLeapYear(year) == true)
        {
            return 29;
            break;
        }
        else
        {
            return 28;
            break;
        }
        break;
    case 3:
        return 31;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 31;
        break;
    case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
    case 12:
        return 31;
        break;
    }
}

bool DateMenager::isLeapYear(int year)
{
    return (year == 2000 || year % 4 == 0);
}

int DateMenager::convertDateIntoNumber(string date)
{
    string dateNoHyphen = "";
    int dateNumberId = 0;

    SupplementaryMethods supplementaryMethods;

    for(int i = 0; i < date.length(); i++)
    {
        if(date[i] != '-')
        {
            dateNoHyphen += date[i];
        }
    }

    dateNumberId = supplementaryMethods.conversionStringToInteger(dateNoHyphen);

    return dateNumberId;
}
