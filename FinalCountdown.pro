QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14
CONFIG -= app_bundle
LIBS += -lws2_32

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    controls.cpp \
    deck.cpp \
    deckdatabase.cpp \
    deckreader.cpp \
    main.cpp \
    mainwindow.cpp \
    probabilitymachine.cpp

HEADERS += \
    card.h \
    controls.h \
    deck.h \
    deckdatabase.h \
    deckreader.h \
    mainwindow.h \
    probabilitymachine.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
