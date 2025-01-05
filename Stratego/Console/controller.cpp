#include "controller.h"

Controller::Controller(Game& game, View& view):m_game(game), m_view(view){
    m_gameType = NORMAL;
}

void Controller::play(){
    m_view.displayWelcome();
    std::string filenameRed = "inputRed.txt";
    std::string filenameBlue = "inputBlue.txt";
    Player& playerRed = m_game.getAllPlayers().at(0);
    Player& playerBlue = m_game.getAllPlayers().at(1);

    while(true){
        switch(m_game.getState()){
        case NOT_STARTED:
            m_game.start();
            break;
        case PREPARE_BOARD:
            m_game.clearBoard();
            m_game.convertsFileToVector(filenameRed, playerRed);
            m_game.convertsFileToVector(filenameBlue, playerBlue);
            m_game.placementOfPiece(playerRed.getPiecesOfPlayer(),playerBlue.getPiecesOfPlayer());
            m_gameType = m_view.askGameType("Enter 1 for normal mode - Enter 2 for visible after reveal mode");
            break;

        case MOVE_PIECE:
            playMovePiece();
            break;

         case TURN_END:
            m_game.nextPlayer();
            break;

         case GAME_OVER:
            m_view.displayWinner();
            break;
        }

    }
}

void Controller::playMovePiece(){
    m_view.displayBoard();
    m_view.displayCurrentPlayer();
    Position position = m_view.askPosition();
    while (!m_game.getBoard().isPieceInsideSquare(position) ||!m_game.isOwnPiece(position) ||
           !m_game.getBoard().isPieceMoveable(position)){
        m_view.displayError("Error : this position does not contain a piece or this piece is not "
                            "yours or this cannot be moved, please enter a new position!");
        position = m_view.askPosition();
    }
    m_view.displayMovementPossibilities(position);
    Movement movement = m_view.askMovement(m_game.getBoard().getSquare(position).getPiece());
    while(!m_game.canMovePiece(position,movement)){
        m_view.displayError("Error : this movement is invalid, please enter"
                            "a new movement!");
        movement = m_view.askMovement(m_game.getBoard().getSquare(position).getPiece());
    }
    m_game.move(position, movement, m_gameType);
}


