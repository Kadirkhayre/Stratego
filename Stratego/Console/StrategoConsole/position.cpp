#include "position.h"

Position::Position(int row, int column):m_row(row),m_column(column){}

int Position::getRow()const{
    return m_row;
}

int Position::getColumn() const{
    return m_column;
}

Position Position::nextPosition (Direction direction){
    int deltaRow = 0;
    int deltaColumn = 0;

    switch(direction){
        case WEST:
            deltaColumn = -1;
            break;

        case EAST:
            deltaColumn = 1;
            break;

        case NORTH:
            deltaRow = -1;
            break;

        case SOUTH:
            deltaRow = 1;
        break;
    }
    return Position(m_row+deltaRow, m_column+deltaColumn);
}
