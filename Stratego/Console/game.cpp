#include "game.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>

Game::Game(){
    m_state = NOT_STARTED;
    m_currentPlayer = &m_allPlayers.at(0);
}

void Game::start(){
    m_board = Board();
    m_currentPlayer = &m_allPlayers.at(0);

    if(m_state!=NOT_STARTED){
        throw std::invalid_argument("The state must be NOT_STARTED ! ");
    }

    m_state=PREPARE_BOARD;
}

void Game::placementOfPiece(std::vector<Piece> &piecesRed, std::vector<Piece> &piecesBlue){
    if(m_state!= PREPARE_BOARD){
        throw std::invalid_argument("The state muste be PREPARE_BOARD !");
    }
    int compteur = 0;
    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < m_board.getSize() ; j++){
            Position position(i,j);
            m_board.getSquare(position).setPiece(&piecesBlue.at(compteur));
            compteur++;
        }
    }
    compteur = 0;
    for (int i = m_board.getSize()-1 ; i > m_board.getSize() - 5 ; i--){
        for (int j = 0 ; j < m_board.getSize() ; j++){
            Position position(i,j);
            m_board.getSquare(position).setPiece(&piecesRed.at(compteur));
            compteur++;
        }
    }
    m_state = MOVE_PIECE;

}
void Game::convertsFileToVector (std::string name, Player& player){
    std::fstream file(name);
    std::string str;

    while(file >> str){
        Piece piece = Piece(str, player.getColor());
        player.getPiecesOfPlayer().push_back(piece);
    }
}

bool Game::canMovePiece(Position& position, Movement& movement){
    if(m_state!=MOVE_PIECE){
        throw std::invalid_argument("The state must be MOVE_PIECE");
    }
    return m_board.canMove(position, movement);
}

void Game::move(Position &position, Movement& movement, GameType gameType){
    if(m_state!=MOVE_PIECE){
        throw std::invalid_argument("The state must be MOVE_PIECE");
    }
    Piece pieceCurrentPlayer = *m_board.getSquare(position).getPiece();
    Piece* piece = m_board.move(position, movement, gameType);

    if (piece != nullptr && piece->getSymbol() == "D"){
        if (piece->getColor() == RED){
            m_allPlayers[0].setHasFlag(true);
        }
        else{
            m_allPlayers[1].setHasFlag(true);
        }
    }

    if (gameOver()){
        m_state = GAME_OVER;
    }
    else{
        m_state = TURN_END;
    }
}

bool Game::gameOver(){
    return !canMoveAtLeastOnePiece() || isFlagCaptured();
}

void Game::nextPlayer(){
    if(m_state !=TURN_END){
        throw std::invalid_argument("The state must be TURN_END");
    }
    if(m_currentPlayer->getColor() == m_allPlayers.at(0).getColor()){
        m_currentPlayer = &m_allPlayers.at(1);
    }
    else{
        m_currentPlayer = &m_allPlayers.at(0);
    }
    m_state = MOVE_PIECE;
}

std::string Game::getWinner(){
    if (m_state != GAME_OVER){
        throw std::invalid_argument("The state must be GAME_OVER");
    }
    m_state = PREPARE_BOARD;

    if(!isFlagCaptured()){
        if(countPieces(m_allPlayers[0]) > countPieces(m_allPlayers[1])){
            return "RED";
        }
        else if (countPieces(m_allPlayers[0]) < countPieces(m_allPlayers[1])){
            return "BLUE";
        }
        else{
            return NULL;
        }
    }
    else{
        if(m_allPlayers[0].isHasFlag()){
            return "RED";
        }
        else{
            return "BLUE";
        }
    }
}

void Game::clearBoard(){
    for (int i = 4  ; i  <= 5 ; i ++){
        for (int j = 0 ; j < m_board.getSize() ; j++){
            Position position(i,j);
            m_board.getSquare(position).setPiece(nullptr);

        }
    }
    m_currentPlayer = &m_allPlayers.at(0);
}

bool Game::isOwnPiece (Position& position){
    return m_currentPlayer->getColor() == m_board.getSquare(position).getPiece()->getColor();
}

std::vector <Movement> Game::movementPossibilitiesPiece(Position& position){
    return m_board.movementPossibilities(position);
}

bool Game::isInside(Position &position){
    return m_board.isInside(position);
}

bool Game::isFlagCaptured(){
    return m_allPlayers[0].isHasFlag() || m_allPlayers[1].isHasFlag();
}

int Game::getBoardSize(){
    return m_board.getSize();
}

Board& Game::getBoard(){
    return this->m_board;
}

State Game::getState(){
    return this->m_state;
}

Player* Game::getCurrentPlayer(){
    return this->m_currentPlayer;
}
std::vector<Player> & Game::getAllPlayers(){
    return m_allPlayers;
}

std::vector <Piece> Game::getAvailablePiecesPlayer(){
    return m_currentPlayer->getPiecesOfPlayer();
}

//done
bool Game::canMoveAtLeastOnePiece(){
    for(int i = 0; i<m_board.getSize();i++){
        for(int j = 0; j<m_board.getSize();j++){
            Position position(i,j);
            if(m_board.isPieceInsideSquare(position)){
                if(m_board.movementPossibilities(position).size()>0){
                    return true;
                }
            }
        }
    }
    return false;
}


int Game::countPieces(Player player){
    return player.getNumberPieces();
}


