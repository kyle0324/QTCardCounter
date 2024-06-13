#include "deckdatabase.h"

deckDataBase::deckDataBase(){
    DRIVER = QString("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER)) {
        qWarning() << "ERROR: driver not available";
    }
}

void deckDataBase::open(){
    db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName("decks.sqlite");
    if(!db.open()) {
        qWarning() << "ERROR: " << db.lastError();
    }
    buildDatabase();
}

void deckDataBase::close() {
    QSqlDatabase::removeDatabase(DRIVER);
    db.close();
}

void deckDataBase::buildDatabase() {
    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS DECKS");
    query.exec("DROP TABLE IF EXISTS CARDS");

    query.exec("CREATE TABLE DECKS (name TEXT");
    query.exec("CREATE TABLE CARDS (deckName TEXT, name TEXT, quantity INTEGER(8), category TEXT, found INTEGER(8)");
}

void deckDataBase::addDeck(string name, deck Deck){
    QString Name = QString::fromStdString(name);
    QSqlQuery query;
    query.prepare("INSERT INTO DECKS (name) values (?)");
    query.addBindValue(Name);
    query.exec();

    vector<card> submittedCards = Deck.getCards();

    for(size_t i = 0; i < submittedCards.size(); i++){
        QSqlQuery cards;
        cards.prepare("INSERT INTO CARDS (deckName, name, quantity, category, found) values (?,?,?,?,?)");
        cards.addBindValue(Name);
        cards.addBindValue(QString::fromStdString(submittedCards[i].getname()));
        cards.addBindValue(submittedCards[i].getQuantity());
        cards.addBindValue(QString::fromStdString(submittedCards[i].getCategory()));
        cards.addBindValue(0);
        cards.exec();
    }
}

bool deckDataBase::checkdeck(string name){
    QString Name = QString::fromStdString(name);
    QSqlQuery query;
    query.exec("SELECT name FROM decks");
    query.next();
    QString test = query.value(0).toString();
    if(Name != test){
        return false;
    }
    return true;

}
