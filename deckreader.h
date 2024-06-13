#ifndef DECKREADER_H
#define DECKREADER_H
#include "deck.h"
#include <fstream>
#include <string>
#include <iomanip>

class deckreader
{
private:
    string filename;
    string deckname;
    void buildDeck();
    deck Deck;
    int testfile(string filename);

public:
    deckreader(){};
    deckreader(string FileName, string Deckname, deck &UserDeck){
        if (testfile(FileName) == -1){
            UserDeck.setName("null");
        }
        else{
            filename = FileName;
            deckname = Deckname;
            buildDeck();
            UserDeck = Deck;
        }
    };
};

#endif // DECKREADER_H
