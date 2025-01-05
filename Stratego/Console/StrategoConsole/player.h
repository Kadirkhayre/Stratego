#ifndef PLAYER_H
#define PLAYER_H
#include "color.h"
#include "piece.h"
#include <vector>

/**
 * @brief The Player class
 */

class Player
{
private:
    bool m_hasFlag;
    Color color;
    std::vector<Piece> m_piecesOfPlayer{};
public:
    /**
     * Constructor
     * @brief Constructor of Player
     * @param the given color
     */
    Player(Color color);

    /**
     * Method isHasFlag()
     * @brief getter of m_hasFlag
     * @return a boolean of m_hasFlag
     */
    bool isHasFlag();

    /**
     * Method setHasFlag()
     * @brief setter of m_hasFlag with @param hasFlage
     * @param hasFlag a boolean
     */
    void setHasFlag(bool hasFlag);

    /**
     * Method getColor()
     * @brief getter of color
     * @return a Color
     */
    Color getColor();

    /**
     * Method getNumberPieces()
     * @brief get the number of pieces of m_piecesOfPlayers
     * @return a int of number of pieces
     */
    int getNumberPieces();

    /**
     * Method getPiecesOfPlayer()
     * @brief getter of m_piecesOfPlayer
     * @return a vector<Piece> by reference
     */
    std::vector<Piece>& getPiecesOfPlayer();

};

#endif // PLAYER_H
