#include "deck.h"

string deck::getName(){
    return name;
}

void deck::setName(string Name){
    name = Name;
}

void deck::setCards(vector<card> Cards){
    cards = Cards;
}

vector<card> deck::getCards(){
    return cards;
}

int deck::getDeckSize(){
    int total = 0;
    for(size_t i = 0; i<cards.size(); i++){
        total = total + cards[i].getQuantity();
    }
    return total;
}
