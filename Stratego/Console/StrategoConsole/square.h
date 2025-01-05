#ifndef SQUARE_H
#define SQUARE_H

#include "squaretype.h"
#include "piece.h"

/**
 * @brief The Square class
 */

class Square{

private:
    SquareType m_type;
    Piece* m_piece;
public:
    /**
     * Constructor
     * @brief Constructor of Square
     * @param the given type
     */
    Square(SquareType type);

    /**
     * Method getType()
     * @brief getter of m-type
     * @return return a SquareType
     */
    SquareType getType()const;

    /**
     * Method getPiece()
     * @brief getter of m_piece
     * @return a Piece pointer
     */
    Piece* getPiece()const;

    /**
     * Method setPiece()
     * @brief setter of m-piece
     * @param piece a Pointer Piece to change
     */
    void setPiece(Piece* piece);
};

#endif // SQUARE_H
