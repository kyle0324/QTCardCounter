#ifndef PROBABILITYMACHINE_H
#define PROBABILITYMACHINE_H


#include "deck.h"
#include <iomanip>

class probabilityMachine
{
private:
    vector<card> cards;
public:
    probabilityMachine(vector<card> usercards){
        cards = usercards;
    };
    double checkProbabiltyName(string card_card);
    double checkProbabilityCat(string Category);
};

#endif // PROBABILITYMACHINE_H
