#ifndef SQUARE_H
#define SQUARE_H

#include "squaretype.h"
#include "piece.h"
#include <QLabel>

/**
 * @brief The Square class
 */
class Square: public QLabel{
private:
    SquareType m_type;
    Piece* m_piece;
public:
    static int size;
    /**
     * Constructor
     * @brief Constructor of Square
     * @param the given type
     */
    Square(SquareType type, Piece* piece=nullptr);

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

    /**
     * Method revealPiece()
     * @brief reveal the piece's value
     */
    void revealPiece();

    /**
     * Methode hidePiece()
     * @brief hide the piece's value
     */
    void hidePiece();
};

#endif // SQUARE_H

