#ifndef VIEW_H
#define VIEW_H

#include "game.h"

/**
 * @brief The View class
 */
class View{

private:
    Game& m_game;

    /**
     * Private method robustReadingOfChar()
     * @brief used for board position, the String message is compare to a char and convert to an int
     * @param message a String
     * @return an int of position
     */
    int robustReadingOfChar(std::string message);

    /**
     * Private method robustReadingOfInteger()
     * @brief show a message and ask an int
     * @param message a string
     * @return an int
     */
    int robustReadingOfInteger(std::string message);

    /**
     * Private method isNumber()
     * @brief checks if the string is a number
     * @param str a const string by reference
     * @return true if it is a number, false instead
     */
    bool isNumber(const std::string& str);

    /**
     * Private method makeLine()
     * @brief create and show a line depend on board size
     * @param sizeBoard an int
     */
    void makeLine(int sizeBoard);

    /**
     * Private method askDirection()
     * @brief ask a direction and return it
     * @param message a string
     * @return a Direction
     */
    Direction askDirection(std::string message);

    /**
     * Private method askNumberOfSteps()
     * @brief ask a number of steps
     * @param message a string
     * @return an int
     */
    int askNumberOfSteps(std::string message);

public:
    /**
     * Constructor
     * @brief Constructor of View
     * @param the given game
     */
    View(Game& game);

    /**
     * Method displayWelcome()
     * @brief show the title and developpers
     */
    void displayWelcome();

    /**
     * Method displayCurrentPlayer()
     * @brief show the current player
     */
    void displayCurrentPlayer();

    /**
     * Method displayBoard()
     * @brief show the board and pieces, depend on the current player
     */
    void displayBoard();

    /**
     * Method displayMovementPossibilities()
     * @brief show each possibility for a piece and show them
     * @param position a Position by reference for the piece
     */
    void displayMovementPossibilities(Position& position);

    /**
     * Method askMovement()
     * @brief ask a movement to the current player
     * @param piece a Piece pointer
     * @return a Movement to move the piece
     */
    Movement askMovement(Piece* piece);

    /**
     * Method displayError()
     * @brief show the error
     * @param message a String message of the error
     */
    void displayError(std::string message);

    /**
     * Method askPosition()
     * @brief ask a position to the current player
     * @return a Position
     */
    Position askPosition();

    /**
     * Method displayWinner()
     * @brief show the winner of the game
     */
    void displayWinner();

    /**
     * Method displayAvaiblePiecesOfPlayer()
     * @brief show each player pieces available
     */
    void displayAvailablePiecesOfPlayer();

    /**
     * Method color()
     * @brief set the color on the board for pieces
     * @param color an int of color
     */
    void color(int color);

    /**
     * Method askGameType(message)
     * @brief ask the type of the game, if it's normal or face and reveal
     * @param message to display
     * @return the gametype
     */
    GameType askGameType(std::string message);

};

#endif // VIEW_H
