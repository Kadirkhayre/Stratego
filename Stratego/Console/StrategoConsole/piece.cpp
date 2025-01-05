#include "piece.h"
#include <string>

Piece::Piece(std::string symbol, Color color):m_symbol(symbol), m_hidden(true), m_color(color){}

bool Piece::attack(Piece& other){
    if (other.getSymbol() == "B"){
        if (getSymbol() == "2"){
            return true;
        }
        return false;
    }

    if (other.getSymbol() == "D"){
        return true;
    }

    int current = std::stoi(m_symbol);
    int opponnent = std::stoi(other.m_symbol);

    if (current == 1 && opponnent == 10){
        return true;
    }
    return current > opponnent;
}

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
