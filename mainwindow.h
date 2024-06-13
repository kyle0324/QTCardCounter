#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controls.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void CheckProbability();
    void NewDeck();
    void UpdateDeck();
private:
    Ui::MainWindow *ui;
    controls control;
};
#endif // MAINWINDOW_H
