#include "player.h"

Player::Player(Color color)
{
    this->color = color;
    this->m_hasFlag = false;

}


bool Player::isHasFlag(){
    return this->m_hasFlag;
}

void Player::setHasFlag(bool hasFlag){
    this->m_hasFlag = hasFlag;
}


Color Player::getColor(){
    return this->color;
}

int Player::getNumberPieces(){
    return this->m_piecesOfPlayer.size();
}

std::vector<Piece> &Player::getPiecesOfPlayer(){
    return m_piecesOfPlayer;
}

