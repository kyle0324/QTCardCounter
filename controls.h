#ifndef CONTROLS_H
#define CONTROLS_H
#include "deckreader.h"
#include "probabilitymachine.h"

class controls
{
private:
    deck Deck;
    string deckName;
    bool checkDeck(string name);
public:
    controls(){};
    void readfile(string filename, string deckname, deck &deck){
        deckreader(filename, deckname, deck);
        Deck = deck;
    };

    deck getDeck(){return Deck;};
    void setDeck(deck newDeck){Deck = newDeck;};
    double runMachineName(vector<card> cards, string name){
        probabilityMachine probs(cards);
        return probs.checkProbabiltyName(name);};
    double runMachineCat(vector<card> cards, string category){
        probabilityMachine probs(cards);
        return probs.checkProbabilityCat(category);
    }
    void updateDeck(vector<card> cards){Deck.setCards(cards);};






};

#endif // CONTROLS_H
