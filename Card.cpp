#include "Card.h"
#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;

#include<string>
    using std::string;

#include <sstream>
    using std::ostringstream;

Card::Card(string symbol, char num) // constructor
{
    this->symbol = symbol;
    this->num = num;
    if(num == 'A')
        value = 1;
    else if(num == '2')
        value = 2;
    else if(num == '3')
        value = 3;
    else if(num == '4')
        value = 4;
    else if(num == '5')
        value = 5;
    else if(num == '6')
        value = 6;
    else if(num == '7')
        value = 7;
    else if(num == '8')
        value = 8;
    else if(num == '9')
        value = 9;
    else if(num == 'X')
        value = 10;
    else if(num == 'J')
        value = 11;
    else if(num == 'Q')
        value = 12;
    else if(num == 'K')
        value = 13;
    else    
        value = 0;
}

string Card::getSymbol() const // return diamond, heart, etc..
{
    return symbol;
}
char Card::getNum() const // get char value
{
    return num;
}

void Card::setSymbol(string newSymbol) // set symbol = diamond, heart, etc..
{
    symbol = newSymbol;
    // if symbol changed, then color will adjusted when call color
}
void Card::setNum(char newNum) // set the char value of the card
{
    num = newNum; 

    //re-adjusting the integer value
    if(num == 'A')
        value = 1;
    else if(num == '2')
        value = 2;
    else if(num == '3')
        value = 3;
    else if(num == '4')
        value = 4;
    else if(num == '5')
        value = 5;
    else if(num == '6')
        value = 6;
    else if(num == '7')
        value = 7;
    else if(num == '8')
        value = 8;
    else if(num == '9')
        value = 9;
    else if(num == 'X')
        value = 10;
    else if(num == 'J')
        value = 11;
    else if(num == 'Q')
        value = 12;
    else if(num == 'K')
        value = 13;
    else    
        value = 0;
}

int Card::getValue() const// return the integer value of card
{
    return value;
}

string Card::color() const// return the correct color format of the card
{
    string returnColor = "\033[30;47m"; // assume black

    if(symbol == "♦" || symbol == "♥")
    {
        returnColor = "\033[31;47m"; // red
    }

    return returnColor;
}