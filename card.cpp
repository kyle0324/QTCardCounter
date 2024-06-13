#include "card.h"

string card::getname(){
    return name;
}

int card::getQuantity(){
    return quantity-used;
}

string card::getCategory(){
    return category;
}

void card::updateUsed(){
    used = getUsed() + 1;
}

int card::getUsed(){
    return used;
}
