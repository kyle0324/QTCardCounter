#include "deckreader.h"

void deckreader::buildDeck(){
    fstream file;
    file.open(filename, ios::in);
    string line;
    vector<int> quantities = {};
    vector<string> categories = {};
    vector<string> names = {};

    size_t pos1, pos2;
    while(getline(file, line)){
        pos1 = line.find(',');
        int quantity =  stod(line.substr(pos1+1));
        pos2 = line.find_last_of(',');
        string category = line.substr(pos2+1);
        string name = line.substr(0,pos1);

        names.push_back(name);
        quantities.push_back(quantity);
        categories.push_back(category);
    }

    vector<card> cards;


    for (size_t i = 0; i < names.size(); i++){
        card Card = card(names[i], quantities[i], categories[i]);
        cards.push_back(Card);
    }

    Deck.setName(deckname);
    Deck.setCards(cards);
    file.close();

}

int deckreader::testfile(string filename){
    ifstream input_stream;
    input_stream.open(filename.c_str(), ios::in);
    if(!input_stream) {
      return -1;
}
    else{
        return 0;
    }
}

