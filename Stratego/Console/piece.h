#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "color.h"
#include "movement.h"

/**
 * @brief The Piece class
 */
class Piece{

private:
    std::string m_symbol;
    bool m_hidden;
    Color m_color;

public:
    /**
     * Constructor
     * @brief Constructor of Piece
     * @param symbol the given symbol
     * @param color the given color
     */
    Piece(std::string symbol, Color color);

    /**
     * Method attack()
     * @brief checks if the attack to another piece is successful
     * @param other a Piece by reference
     * @return a boolean true if the attack is successful, false instead
     */
    bool attack (Piece& other);


    /**
     * Method getSymbol()
     * @brief getter of m_symbol
     * @return a String of symbol of the piece
     */
    std::string getSymbol();

    /**
     * Method isHidden()
     * @brief getter of m_hidden
     * @return return a boolean
     */
    bool isHidden();

    /**
     * Method setHidden()
     * @brief set the m_hidden with @param hidden
     * @param hidden a boolean
     */
    void setHidden(bool hidden);

    /**
     * Method getColor()
     * @brief getter of m_color
     * @return return a Color
     */
    Color getColor();

    /**
     * Method setSymbol()
     * @brief setter of m_symbol
     * @param symbol a String used to change
     */
    void setSymbol (std::string symbol);

    /**
     * Method isMoveable()
     * @brief checks if the piece is not "D" or "B"
     * @return a boolean true if is moveable, false instead
     */
    bool isMoveable();
};

#endif // PIECE_H
