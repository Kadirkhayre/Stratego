#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include "position.h"
#include "direction.h"
#include "gametype.h"

/**
 * @brief The Board class
 */
class Board{    

private:
    static const int SIZE = 10;
    Square m_squares[SIZE][SIZE];
public:
    /**
     * Constructor
     * @brief Constructor of Board
     */
    Board();
    /**
     * Method getSquare
     * @brief A getter of square
     * @param position a reference Position used to get the sqaure
     * @return a Square by reference
     */
    Square& getSquare(Position &position);

    /**
     * Method getSize()
     * @brief A getter of the board size
     * @return an int of size
     */
    int getSize();

    /**
     * Method isInside()
     * @brief Check if the position is inside the board
     * @param position a Position by reference
     * @return a boolean true if is it in, false instead
     */
    bool isInside(Position& position);

    /**
     * Method isPieceInsideSquare()
     * @brief Check if the square at the Position contain a Piece
     * @param position a Position by reference
     * @return a boolean true if there is inside, false instead
     */
    bool isPieceInsideSquare(Position& position);

    /**
     * Method isDifferentPieceColor()
     * @brief Check if the color of piece at position is different
     * to the color of piece of newPosition
     * @param position a Position by reference
     * @param newPosition another Position by reference to compare
     * @return a boolean true if there are different, false instead
     */
    bool isDifferentPieceColor(Position& position, Position& newPosition);

    /**
     * Method isLakeSquare()
     * @brief checks if the square is a Lake
     * @param position a Position by reference
     * @return return a boolean true if there is one, false instead
     */
    bool isLakeSquare(Position& position);

    /**
     * Method movementPossibilities()
     * @brief search each movement possibilities for a piece
     * and put it on a vector of movement
     * @param position a Position by reference
     * @return a vector<Movement> contains each possibility of movement
     */
    std::vector <Movement> movementPossibilities(Position& position);

    /**
     * Method canMove()
     * @brief checks if the piece on a specific position can do the movement
     * @param position a Position by reference
     * @param movement a Movement by reference
     * @return a boolean true if it can move, false instead
     */
    bool canMove (Position& position, Movement& movement);

    /**
     * Method move()
     * @brief move the piece at the position to a new position with movement
     * @param position a Position by reference
     * @param movement a Movement by reference
     * @return a Piece pointer who it has been killed if there is one
     */
    Piece* move(Position& position, Movement& movement, GameType gameType);

    /**
     * Method isPieceMoveable()
     * @brief call piece->isMoveable()
     * check if the piece is not a "D" or a "B" on the position
     * @param position a Position reference
     * @return a boolean true if it isn't, false instead
     */
    bool isPieceMoveable(Position& position);
};

#endif // BOARD_H
