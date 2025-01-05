#ifndef POSITION_H
#define POSITION_H

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
     * Method equals()
     * @brief checks if the position equals to the other position
     * @param other a Position
     * @return true if is it equals, false instead
     */
    bool equals (Position other);
};

#endif // POSITION_H
