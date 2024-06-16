#ifndef Card_h
#define Card_h

#include<string>

class Card
{
    public:
        Card(std::string symbol, char num); // constructor
        Card() = default;

        //accessor 
        std::string getSymbol() const; // diamond, heart, etc..
        char getNum() const;
        int getValue() const;

        // mutator
        void setSymbol(std::string);
        void setNum(char);

        std::string color() const; // get the correct color output format


    private:
        std::string symbol = " "; // heart, diamond, etc..
        char num = ' '; // value of the card
        int value; //actual value


};




#endif
