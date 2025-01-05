QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    main.cpp \
    mainwindow.cpp\
    gstrategoboard.cpp \
    obj.cpp \
    piece.cpp \
    position.cpp \
    square.cpp

HEADERS += \
    color.h \
    game.h \
    mainwindow.h\
    gstrategoboard.h \
    obj.h \
    piece.h \
    position.h \
    square.h \
