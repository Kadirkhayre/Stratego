#include "position.h"

Position::Position(int row, int column):m_row(row),m_column(column){}

int Position::getRow()const{
    return m_row;
}

int Position::getColumn() const{
    return m_column;
}

bool Position::equals (Position other){
    return m_row == other.m_row && m_column == other.m_column;
}
