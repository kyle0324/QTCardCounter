#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class card
{
private:
    string name;
    int quantity;
    string category;
    int used;
public:
    card(){};
    card(string Name, int Quantity){
        name = Name;
        quantity = Quantity;
        category = "null";
        used = 0;
    };
    card(string Name, int Quantity, string Category){
        name = Name;
        quantity = Quantity;
        category = Category;
        used = 0;
    };
    card(string Name, int Quantity, string Category, int Used){
        name = Name;
        quantity = Quantity;
        category = Category;
        used = Used;
    }

    string getname();
    int getQuantity();
    string getCategory();
    void updateUsed();
    int getUsed();
};

#endif // CARD_H
