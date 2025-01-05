#include "piece.h"
#include <string>

Piece::Piece(std::string symbol, Color color):m_symbol(symbol), m_hidden(true), m_color(color){}


bool Piece::isMoveable(){
    return m_symbol != "D" && m_symbol != "B";
}

std::string Piece::getSymbol(){
    return m_symbol;
}

bool Piece::isHidden(){
    return m_hidden;
}

void Piece::setHidden(bool hidden){
    m_hidden = hidden;
}

Color Piece::getColor(){
    return m_color;
}

void Piece::setSymbol(std::string symbol){
   m_symbol = symbol;
}
