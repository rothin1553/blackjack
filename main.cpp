#include<iostream>
    using std::cin;
    using std::cout;
    using std::endl;

#include<string>
    using std::string;

#include<random>
#include<unistd.h>
#include <sstream>
    using std::ostringstream;
#include<fstream>
    using std::ofstream;
    using std::ifstream;
#include<vector>
    using std::vector;

#include "Card.h"
#include "Deck.h"
#include "NoEnter.h"

void prototype2p1(Card card, Deck deck, Deck noPlayDeck, bool top = true);
void backOfCard(int numOfCard, int startAt = 0, bool firstPrint = false);
int  getRandomInt(int lowerBound, int upperBound);
void loading();
void writeToFile(int dealerWin, int playerWin);
void showStat();
void print(string str, bool constSpeed = true, unsigned long times = 41704);

// int main()
// {
//     Deck

    

//     return 0;
// }

///----------------- old main

int main()
{
    loading();

    NoEnter command;
    command.on();

    print("This is BlackJack from \033[1;31m120TH-Grammer\033[0m\n\t--->(Development Stage CODE:\033[35malpha\033[0m]:)");
    usleep(2187042);

    Deck deck;
    deck.setStatus(true);
    Deck deck1;

    //deck.display();
    int money = 100;
    int dealer = 0;
    int player = 0;

    // cout << "get card:\n";
    char end = '\0';

    bool userFinish = false;
    bool finishGame = false;
    while(end != 'x')
    {
        for(int i = 0; i < 52 && !finishGame; i++)
        {
            // if(i == 6)
            //     deck.clearPlayDeck();
            //prototype2p1(deck.getCard(), deck);
            //deck1.getCard();

            char cmd = '\0';
            if(!userFinish && i > 3)
            {    
                cout << "Press '2' to draw card, Press 'x' to finish.\n";
                //cin >> cmd;
                cmd = getchar();    
            
                //cin.ignore(256, '\n');
            }
            else
            {
                if(i == 0)
                {
                    cmd = '1';
                }
                else if(i == 1)
                {
                    cmd = '2';
                }
                else if(i == 2)
                {
                    cmd = '1';
                }
                else if(i == 3)
                {
                    cmd = '2';
                }
            }

        
            if(cmd == '1' || userFinish)
                prototype2p1(deck.getCard(), deck, deck1, true);
            else if(cmd == '2')
                prototype2p1(deck1.getCard(), deck1, deck, false);
            else if(cmd == 'x' )
            {
                deck.setStatus(false);
                userFinish = true;

                if((deck.totalValue() < 21) && (deck.totalValue() < deck1.totalValue()))
                {
                    prototype2p1(deck.getCard(), deck, deck1, true);
                }
                else
                {
                    system("clear");
                    cout << "\n\n";
                    backOfCard(1);
                }
            }
            //system("clear");
            deck.showCard();
            cout << "value: " << deck.totalValue() << endl;
            deck1.showCard();
            cout << "value: " << deck1.totalValue() << endl;

            if(userFinish)
            {
                // deck.setStatus(false);
                usleep(517044);
            }

            if((deck.totalValue() == 21 || deck1.totalValue() == 21 || deck.totalValue() > 21 || deck.totalValue() >= deck1.totalValue() || deck1.totalValue() > 21) && (deck1.size() >= 2))
            {
                finishGame = true;
                deck.setStatus(false); // open dealer card

                if(cmd != 'x')
                {
                    system("clear");
                    cout << "\n\n";
                    backOfCard(1);
                    deck.showCard();
                    cout << "value: " << deck.totalValue() << endl;
                    deck1.showCard();
                    cout << "value: " << deck1.totalValue() << endl;
                }
            }

        }

        if((deck.totalValue() >= deck1.totalValue() && deck.totalValue() <= 21) || deck1.totalValue() > 21)
        {
            cout << "\n\n*****Roth win!!!\n\n";
            money--;
            dealer++;
        }
        else
        {
            cout << "\n\n*****You win!!!\n\n";
            money++;
            player++;
        }

        usleep(1492123);

        cout << "\n\nCASH: " << money << "\n\n";
        cout << "press 'x' to end game, otherwise press any key.\n";

        end = getchar();
        //cin >> end;
        //cin.ignore(256, '\n');

        system("clear");
        deck.clearPlayDeck();
        deck.setStatus(true);
        deck1.clearPlayDeck();
        userFinish = false;
        finishGame = false;
    }

    writeToFile(dealer, player);

    showStat();

    return 0;
} //-------------------- end old main


void prototype2p1(Card card, Deck deck, Deck noPlayDeck, bool top)  // 2.1 daiki mode
{
    ostringstream line1, line2, line3; 

    usleep(212211);

    string reset =  "\033[0m";

    char num = card.getNum();
    string symbol = card.getSymbol();
    string color = card.color();

    if(deck.isClose())
    {
        string cardS1 = "\033[41;30m{✼\033[41;37m✼\033[41;30m✼}\033[0m";
        string cardS2 = "\033[41;30m{\033[41;37mR\033[41;30m❁\033[41;37mI\033[41;30m}\033[0m";
        string cardS3 = "\033[41;30m{✼\033[41;37m✼\033[41;30m✼}\033[0m";

        line1 << cardS1 << '\t';
        line2 << cardS2 << '\t';
        line3 << cardS3 << '\t';
    }
    else
    {
        line1 << color << symbol << "    " << reset << '\t';
        line2 << "\033[1m" << color << "  " << num << "  " << reset << '\t'; // middle bold
        line3 << color << "    " << symbol << reset << '\t';
    }

    system("clear");

    // print out all three lines to form the card 
    cout << "\n\n\t\t"<< line1.str() << '\n'
         << "\t\t"<< line2.str() << '\n'
         << "\t\t"<< line3.str() << "\033[0m\n\n";

    /// set each line to empty
    line1.str("");
    line2.str("");
    line3.str("");

    // clear the flag for each line
    line1.clear();
    line2.clear();
    line3.clear();

    if(top)
    {
        deck.showCard(1); /// display one less whole deck
        cout << "value: " << deck.totalValue(1) << endl;
        noPlayDeck.showCard();
        cout << "value: " << noPlayDeck.totalValue() << endl;
    }

    else
    {
        noPlayDeck.showCard();
        cout << "value: " << noPlayDeck.totalValue() << endl;
        deck.showCard(1); /// display one less whole deck
        cout << "value: " << deck.totalValue(1) << endl;
    }

    usleep(417044);

    system("clear");
    cout << "\n\n";
    backOfCard(1);

}

void backOfCard(int numOfCard, int startAt, bool firstPrint)
{
    ostringstream line1, line2, line3; 

    string cardS1 = "\033[41;30m{✼\033[41;37m✼\033[41;30m✼}\033[0m";
    string cardS2 = "\033[41;30m{\033[41;37mR\033[41;30m❁\033[41;37mI\033[41;30m}\033[0m";
    string cardS3 = "\033[41;30m{✼\033[41;37m✼\033[41;30m✼}\033[0m";

    for(int i = 0; i < numOfCard; i++)
    {
        if(i >= startAt)
        {
            line1 << cardS1 << '\t';
            line2 << cardS2 << '\t';
            line3 << cardS3 << '\t';
        }

        else
        {
            line1 << "     \t";
            line2 << "     \t";
            line3 << "     \t";
        }
    }

    if(firstPrint) // first time print all close cards //new line
    {
        cout << "\n\n\t\t"<< line1.str() << '\n'
             << "\t\t"<< line2.str() << '\n'
             << "\t\t"<< line3.str() << "\033[0m\n\n";
    }

    else // no new line
    {
        cout << "\t\t" << line1.str() << '\n'
             << "\t\t" << line2.str() << '\n'
             << "\t\t" << line3.str() << "\033[0m\n\n";
    }

    /// set each line to empty
    line1.str("");
    line2.str("");
    line3.str("");

    // clear the flag for each line
    line1.clear();
    line2.clear();
    line3.clear();
}

void loading()
{
    string color{"\033[42m \033[0m"};
    //char dot = ' ';
    string tempStr;
    
    for(int i = 0; i < 25; i++)
    {
        int times = getRandomInt(41704,217044);
        system("clear");

        cout << "\n\n\t\tBlackJack by \033[1;31m120TH-Grammer\033[0m\n\nLOADING...\n\n";
        
        for(int j = 0; j <= i; j++)
        {
            cout << color << ' ';
        }
        cout << string(55-(i*2), ' ') <<  (i+1) * 4 << "%" << endl;
        usleep(times); 
    }
    usleep(957044);
    system("clear");
}

int getRandomInt(int lowerBound, int upperBound)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(lowerBound, upperBound);

    return dist(mt);
}

void writeToFile(int dealerWin, int playerWin)
{
    ofstream outfile{"stat.txt", std::ios::app};

    outfile << string(50, '-') << endl;
    outfile << "Total play: " << dealerWin + playerWin << "\t\t\tPlay win%: " 
            << (playerWin * 100) / (dealerWin + playerWin) << '%' << endl;
    outfile << "Dealer win: " << dealerWin << "\t\t\tPlayer win: " << playerWin << endl;
    

    outfile.close();
}

void showStat()
{
    ifstream infile{"stat.txt"};

    vector<string> data;
    if(infile.is_open())
    {
        while(!infile.eof())
        {
            string line;
            getline(infile, line);
            data.push_back(line);
        }

        int size = data.size();
        int start = size - 10;
        if(start < 0)
        {
            start = 0;
        }

        cout << "The most recent stat:\n";
        for(; start < size; start++)
        {
            cout << data[start] << endl;
        }
    }

    infile.close();

}

void print(string str, bool constSpeed, unsigned long times)
{
    bool allow = false; // set flag for small text
    if(str.size() < 256)
    {
        allow = true; // if small text then allow random
        // cout << str.size();
        // cin.get();
    }

    string tempStr;
    for(unsigned long i = 0; i < str.size(); i++)
    {
        system("clear");
        tempStr.push_back(str[i]);
        cout << "\n\n\n" << tempStr << "\033[0m" << endl;

        if(!constSpeed && allow)
        {
            times = getRandomInt(1704, 41704);
        }

        usleep(times); 
    }
}