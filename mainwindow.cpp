#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    controls control();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CheckProbability(){
    QString cardname = ui->cardName_search->displayText();
    vector<card> cards = control.getDeck().getCards();
    if(cardname == ""){
        QString cardCategory = ui->category_search->displayText();
        double result = control.runMachineCat(control.getDeck().getCards(), cardCategory.toStdString().c_str());
        ui->probability->setText(QString::number(result));
        ui->cardName->setText(cardCategory);
    }
    else{
        double result = control.runMachineName(control.getDeck().getCards(), cardname.toStdString().c_str());
        ui->probability->setText(QString::number(result));
        ui->cardName->setText(cardname);
    }
};
void MainWindow::NewDeck(){
    deck Deck;
    QString deckname = ui->add_deck_name->displayText();
    QString filename = ui->DeckSource->displayText();
    control.readfile(filename.toStdString().c_str(), deckname.toStdString().c_str(), Deck);
    if (Deck.getName() == "null"){
        ui->conNewDeck->setText("failure");
    }
    else{
        control.setDeck(Deck);
        ui->conNewDeck->setText("success!");

        int count = Deck.getDeckSize();
        ui->cardCount->setText(QString::number(count));
    }
};

void MainWindow::UpdateDeck(){
    int check = 0;
    QString badInput = "failure";
    QString cardname = ui->drawn_card->displayText();
    vector<card> usercards = control.getDeck().getCards();

    for(size_t i = 0; i<usercards.size(); i++){
        if(cardname.toStdString().c_str() == usercards[i].getname()){
            if(usercards[i].getQuantity() == 0){
                badInput = badInput + " no " + cardname + " left";
            }
            else{
                usercards[i].updateUsed();
                check = 1;
            }
        }
    }
    if(check == 0){
        ui->conUpdateDeck->setText(badInput);
    }
    else{
        control.updateDeck(usercards);

        int count = control.getDeck().getDeckSize();
        ui->cardCount->setText(QString::number(count));
        ui->conUpdateDeck->setText("success!");
    }
};
