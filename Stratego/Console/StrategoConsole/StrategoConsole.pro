TEMPLATE = app
CONFIG += console # c++11
CONFIG -= app_bundle
CONFIG -= qt
DESTDIR = $$PWD

QMAKE_CXXFLAGS += -std=c++17 -pedantic-errors -Wall

SOURCES += \
        board.cpp \
        controller.cpp \
        game.cpp \
        main.cpp \
        movement.cpp \
        piece.cpp \
        player.cpp \
        position.cpp \
        square.cpp \
        view.cpp \

HEADERS += \
    board.h \
    color.h \
    controller.h \
    direction.h \
    game.h \
    gametype.h \
    movement.h \
    piece.h \
    player.h \
    position.h \
    square.h \
    squaretype.h \
    state.h \
    view.h

DISTFILES += \
    inputBlue.txt \
    inputRed.txt

