#ifndef DECKDATABASE_H
#define DECKDATABASE_H
#include "deck.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <memory>
#include <string>

class deckDataBase
{
private:
    QSqlDatabase db;
    QString DRIVER;
    void buildDatabase();
public:
    deckDataBase();
    void open();
    void close();
    void addDeck(string name, deck Deck);
    void getdeck(string name){};//to do and change to deck instead of void
    bool checkdeck(string name);
};

#endif // DECKDATABASE_H
