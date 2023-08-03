/*
Write a program to play the Card Guessing Game. Your program must give the user the following menu choices:
Guess only the face value of the card.
Guess only the suit of the card.
Guess both the face value and suit of the card.

Before the start of the game, create a deck of cards. Before each guess, use the function 
random_shuffle to randomly shuffle the deck.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void printMenu();
vector<string> createDeck();
void randomShuffle(vector<string> & cards);

int main()
{
    int option;
    char trigger = 'y';

    while(trigger == 'y')
    {    
        printMenu();
        cin >> option;

        vector<string> cards;
        cards = createDeck();

        

        switch(option){
            case 1:
                //guessing face value of card
            {
                string guess;
                randomShuffle(cards);
                cout << "\nFace value guess: ";
                cin >> guess;
                
                string actual;
                actual = cards[0];
                actual = actual.substr(actual.find(':')+1);
                
                if(guess == actual)
                    cout << "CORRECT. YOU WIN.\n" << "Actual Face Value: " << actual << endl;
                else
                    cout << "INCORRECT. YOU LOSE.\n" << "Actual Face Value: " << actual << endl;
                break;
            }
            case 2:
                //guessing the suit
            {   
                string suitGuess;
                randomShuffle(cards);
                cout << "\nSuit guess (Hearts, Clubs, Spades, Diamonds): ";
                cin >> suitGuess;
                
                string actual;
                actual = cards[0];
                actual = actual.substr(0,actual.find(':'));
                
                if(suitGuess == actual)
                    cout << "CORRECT. YOU WIN.\n" << "Actual Suit: " << actual << endl;
                else
                    cout << "INCORRECT. YOU LOSE.\n" << "Actual Suit: " << actual << endl;
                break;
            }
            case 3:
                //guessing btoh
            {
                string suitGuess;
                randomShuffle(cards);
                cout << "\nSuit guess (Hearts, Clubs, Spades, Diamonds): ";
                cin >> suitGuess;
                
                string actual;
                actual = cards[0];
                string actualSuit = actual.substr(0,actual.find(':'));

                string guess;
                cout << "\nFace value guess: ";
                cin >> guess;
                
                string actualValue = actual.substr(actual.find(':')+1);

                if(suitGuess == actualSuit && guess == actualValue)
                    cout << "CORRECT. YOU WIN.\n" << "Actual Card: " << actual << endl;
                else
                    cout << "INCORRECT. YOU LOSE.\n" << "Actual Card: " << actual << endl;
                break;
            }
            default:
            {   
                cout << "That was not an option my dude\n";
                break;
            }
        }
        cout << "\nGo again? [y/n]: ";
        cin >> trigger;
    }    
    return 0;
}

void printMenu()
{
    cout << "Menu Options:\n";
    cout << "Guess only the face value of the card [1]\n";
    cout << "Guess only the suit of the card [2]\n";
    cout << "Guess both the face value and suit of the card [3]\n\n";
    cout << "OPTION (Enter 1,2 or 3): ";
}

vector<string> createDeck()
{
    vector<string> cards;

    string suit = "Spades";
    for(int i = 1; i <=13; i++)
    {
        cards.push_back(suit + ":" + to_string(i));
    }
    suit = "Clubs";
    for(int i = 1; i <=13; i++)
    {
        cards.push_back(suit + ":" + to_string(i));
    }
    suit = "Hearts";
    for(int i = 1; i <=13; i++)
    {
        cards.push_back(suit + ":" + to_string(i));
    }
    suit = "Diamonds";
    for(int i = 1; i <=13; i++)
    {
        cards.push_back(suit + ":" + to_string(i));
    }

    return cards;

}

void randomShuffle(vector<string> & cards)
{
    random_shuffle(cards.begin(), cards.end());
}
