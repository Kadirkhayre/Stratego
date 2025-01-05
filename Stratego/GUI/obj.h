#ifndef OBJ_H
#define OBJ_H

#include "squaretype.h"
#include "piece.h"

class obj
{
private:
    SquareType m_type;
    Piece* m_piece;
public:
    /**
     * Constructor
     * @brief Constructor of Square
     * @param the given type
     */
    obj(SquareType type, Piece* piece=nullptr);

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
