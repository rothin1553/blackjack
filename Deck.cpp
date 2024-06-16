#include "Deck.h"

#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;

#include<string>
    using std::string;

#include <sstream>
    using std::ostringstream;

#include<random>
#include<unistd.h>

#include<algorithm>
    using std::swap;

//card symbols ♠ ♣ ♥ ♦ 

Deck::Deck()
{
    char num[]{'A','2','3','4','5','6','7','8','9','X','J','Q','K'};
    string symbol[4]{"♠", "♣", "♥", "♦"};

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            Card card(symbol[i], num[j]);
            deck.push_back(card);
        }
    }
}

void Deck::display(const vector<Card>& deckStack, int end) const// take a deck to display all of cards in that deck
{

    //prototype2p1(deckStack[deckStack.size()-1]);

    ostringstream line1, line2, line3;

    //string color = "\033[30;47m"; // assume black card
    string reset =  "\033[0m";

    int size = deckStack.size() - end;
    int i = size - 14; // only display 15 cards at a time for screen purpose
    if(i < 0)
    {
        i = 0;
    }

    if(block) // close card #intended for dealer (cpu- no show card)
    {
        string cardS1 = "\033[41;30m{✼\033[41;37m✼\033[41;30m✼}\033[0m";
        string cardS2 = "\033[41;30m{\033[41;37mR\033[41;30m❁\033[41;37mI\033[41;30m}\033[0m";
        string cardS3 = "\033[41;30m{✼\033[41;37m✼\033[41;30m✼}\033[0m";
        //cout << "i: " << i << "\tsize: " << size << "\tdS.size " << deckStack.size() << endl;
        //cin.get();
        char num = deckStack[i].getNum();
        string symbol = deckStack[i].getSymbol();
        string color = deckStack[i].color();

        for(; i < size; i++)
        {
            if(i == 0)
            {
                line1 << color << symbol << "    " << reset << '\t';
                line2 << "\033[1m" << color << "  " << num << "  " << reset << '\t'; // middle bold
                line3 << color << "    " << symbol << reset << '\t';
            }

            else
            {
                line1 << cardS1 << '\t';
                line2 << cardS2 << '\t';
                line3 << cardS3 << '\t';
            }
            

        }
    }

    else // open card, esspecially for player 
    {
        for(; i < size; i++)
        {
            char num = deckStack[i].getNum();
            string symbol = deckStack[i].getSymbol();
            string color = deckStack[i].color();

            line1 << color << symbol << "    " << reset << '\t';

            line2 << "\033[1m" << color << "  " << num << "  " << reset << '\t'; // middle bold

            line3 << color << "    " << symbol << reset << '\t';

        }
    }


    // print out all three lines to form the card 
    cout << "\n\n\t"<< line1.str() << '\n'
         << "\t"<< line2.str() << '\n'
         << "\t"<< line3.str() << "\033[0m\n\n";
}

int Deck::getRandomInt(int lowerBound, int upperBound)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(lowerBound, upperBound);

    return dist(mt);
}


Card Deck::getCard()
{
    int randomIndex = getRandomInt(0, cardLeft-1);

    playDeck.push_back(deck[randomIndex]);

    swap(deck[randomIndex], deck[cardLeft-1]); // swap for no redundnt
    
    cardLeft--; // decrement

    return deck[cardLeft]; // return a card
}

void Deck::showCard(int end)
{
    display(playDeck,end);
}

void Deck::clearPlayDeck(int begin, bool all, int end)
{
    if(all)
    {
        end = playDeck.size();
    }
    cardLeft = 52;
    playDeck.erase(playDeck.begin() + begin, playDeck.begin() + end);
}

int Deck::size()
{
    return playDeck.size();
}

int Deck::totalValue(int less) // less is last value to not add
{
    int total = 0;

    int aceCard = 0;

    for(unsigned long i = 0; i < playDeck.size() - less; i++)
    {
        int cardValue = playDeck[i].getValue();
        if(cardValue == 1 && (total + 11 <= 21)) // 1 and 11 ace card
        {
            cardValue = 11;
            aceCard++;
        }

        else if(cardValue > 10) // for J Q & K worth 10
        {
            cardValue = 10;
        }

        total = total + cardValue;

        if(total > 21 && aceCard > 0)
        {
            total = total - 10;
            aceCard--;
        }
    }

    if(block)
    {
        total = 0;
    }

    return total;
}

void Deck::setStatus(bool closeCard)
{
    block = closeCard;
}
bool Deck::isClose()
{
    return block;
}
