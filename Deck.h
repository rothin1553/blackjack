#ifndef Deck_h
#define Deck_h

#include "Card.h"

#include<vector>
    using std::vector;

class Deck
{
    public:
        Deck(); // constructor get one whole deck of cards

        void display(const vector<Card>&, int end = 0) const;
        Card getCard(); // get one card to the play deck
        void showCard(int end = 0); // show all the card in the play deck
        int  totalValue(int less = 0); // total value of the card in play deck (adjusted to 21)
        int  size(); // return the size of the play deck
        void clearPlayDeck(int begin = 0, bool all = true, int end = 0); // clear, reset all the card in play deck

        void setStatus(bool closeCard); // setting card to close or open card
        bool isClose(); // check if the card is closed or opened


    private:
        vector<Card> deck; // cards in a full deck
        vector<Card> playDeck; // card in the playing deck
        int cardLeft = 52; // card left in the pullable deck
        bool block = false; // flag for closed/opened card

        int getRandomInt(int lowerBound, int upperBound); // get random num


};

// void prototype2p1(Card card);
// void backOfCard(int numOfCard, int startAt = 0, bool firstPrint = false);


#endif
