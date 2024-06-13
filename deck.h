#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <memory>
#include <vector>

class deck{
private:
    string name;
    vector<card> cards;
public:
    deck(){};
    deck(string Name, vector<card> Cards){
        name = Name;
        cards = Cards;
    }
    string getName();
    vector<card> getCards();
    void setName(string Name);
    void setCards(vector<card> Cards);
    int getDeckSize();

};

#endif // DECK_H
