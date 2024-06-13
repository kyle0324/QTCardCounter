#include "probabilitymachine.h"

#include "probabilitymachine.h"

double probabilityMachine::checkProbabiltyName(string card_card){
    double probability;
    double decksize = 0;
    double quantityUsed = 0;
    double quantitySingle= 0;
    for (size_t i = 0; i < cards.size(); i++){
        string name = cards[i].getname();
        if (name == card_card){
            quantitySingle = cards[i].getQuantity();
        }
        quantityUsed = quantityUsed + cards[i].getUsed();
        decksize = decksize + cards[i].getQuantity();

    }
    probability = (quantitySingle)/(decksize+quantityUsed)*100;
    return probability;
}

double probabilityMachine::checkProbabilityCat(string Category){
    double probability;
    double decksize = 0;
    double quantityUsed = 0;
    double quantityCategory = 0;
    double usedCategory = 0;
    for( size_t i = 0; i < cards.size(); i++){
        string category = cards[i].getCategory();
        if(category == Category){
            quantityCategory = quantityCategory + cards[i].getQuantity();
            usedCategory = usedCategory + cards[i].getUsed();
        }
        quantityUsed = quantityUsed + cards[i].getUsed();
        decksize = decksize + cards[i].getQuantity();
    }
    probability = (quantityCategory)/(decksize+quantityUsed)*100;

    return probability;
}
