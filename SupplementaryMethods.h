#ifndef SUPPLEMENTARYMETHODS_H
#define SUPPLEMENTARYMETHODS_H

#include <iostream>

using namespace std;

class SupplementaryMethods
{
public:
    static string conversionIntegerToString(int number);
    int conversionStringToInteger(string number);
    string loadNumber(string text, int positionOfCharacter);
    string loadTextLine();
    string replaceFirstLetterForBigLetterAndRestForSmallLetters(string text);
    char loadCharacter();
    int loadIntegerNumber();
    string replaceAmountWithCommaForAmountWithDot(string text);
};

#endif
