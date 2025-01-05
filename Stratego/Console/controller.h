#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"
#include "view.h"

/**
 * @brief The Controller class
 */
class Controller{

private:
    Game& m_game;
    View& m_view;
    GameType m_gameType;

    /**
     * Private method playMovePiece()
     * @brief does the movement part and ask to the player how to move
     */
    void playMovePiece();

public:
    /**
     * Constructor
     * @brief Constructor of Controller
     * @param game the given game
     * @param view the given view
     */
    Controller(Game& game, View& view);

    /**
     * Method play()
     * @brief The main method of the game, manage each part of the game
     */
    void play();
};


#endif // CONTROLLER_H
