#include "SupplementaryMethods.h"
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <fstream>

string SupplementaryMethods::conversionIntegerToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int SupplementaryMethods::conversionStringToInteger(string number)
{
    int integerNumber;
    istringstream iss(number);
    iss >> integerNumber;

    return integerNumber;
}

string SupplementaryMethods::loadNumber(string text, int positionOfCharacter)
{
    string number = "";
    while(isdigit(text[positionOfCharacter]) == true)
    {
        number += text[positionOfCharacter];
        positionOfCharacter ++;
    }
    return number;
}

string SupplementaryMethods::loadTextLine()
{
    string entry = "";
    getline(cin, entry);
    return entry;
}

string SupplementaryMethods::replaceFirstLetterForBigLetterAndRestForSmallLetters(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string SupplementaryMethods::replaceAmountWithCommaForAmountWithDot(string text)
{
    string newText = "";

    int lengthWord = text.length();

    if(!text.empty())
    {
        for(int i = 0; i < lengthWord; i++)
        {
            if(text[i] == ',')
            {
                newText += ".";
            }
            else
            {
                newText += text[i];
            }
        }
    }

    return newText;
}

char SupplementaryMethods::loadCharacter()
{
    string entry = "";
    char character  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            character = entry[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

int SupplementaryMethods::loadIntegerNumber()
{
    string entry = "";
    int number = 0;

    while (true)
    {
        getline(cin, entry);

        stringstream myStream(entry);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}
