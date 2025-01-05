#ifndef POSITION_H
#define POSITION_H

#include "direction.h"

/**
 * @brief The Position class
 */

class Position {

private:
    int m_row;
    int m_column;

public:
    /**
     * Constructor
     * @brief Constructor of Position
     * @param the given row
     * @param the given column
     */
    Position(int row, int column);

    /**
     * Method getRow()
     * @brief getter of m_row
     * @return an int of row
     */
    int getRow()const;

    /**
     * Method getColumn()
     * @brief getter of m_column
     * @return an int of column
     */
    int getColumn()const;

    /**
     * Method nextPosition()
     * @brief give the next position with the direction
     * @param direction a Direction
     * @return a Position who is the next position
     */
    Position nextPosition (Direction direction);
};

#endif // POSITION_H
