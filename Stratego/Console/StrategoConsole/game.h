#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "gametype.h"
#include "state.h"
#include "player.h"
#include <iostream>

/**
 * @brief The Game class
 */
class Game{

private:
    Board m_board;
    Player* m_currentPlayer;
    std::vector <Player> m_allPlayers{Player(RED), Player(BLUE)};
    State m_state;

    /**
     * Method countPieces()
     * @brief counts each piece the player actually has
     * @param player a Player
     * @return the number of pieces he contains
     */
    int countPieces(Player player);

public:
    /**
     * Constructor
     * @brief Constructor of Game
     */
    Game();
    /**
     * Method start()
     * @brief The beginning of the game, create the board and players
     * create an error if the state is not @bold NOT_STARTED
     */
    void start();

    /**
     * Method placementOfPiece()
     * @brief places on the board each pieces of players
     * create an error if the state is not @bold PREPARE_BOARD
     * @param piecesRed a vector<Piece> containing pieces of player red, by reference
     * @param piecesBlue a vector<Piece> containing pieces of player blue, by reference
     */
    void placementOfPiece(std::vector<Piece> &piecesRed, std::vector<Piece> &piecesBlue);

    /**
     * Method canMovePiece()
     * @brief call the m_board->canMove()
     * create an error if the state is not @bold MOVE_PIECE
     * @param position a Position by reference
     * @param movement a Movement by reference
     * @return a boolean true if it can be moved, false instead
     */
    bool canMovePiece(Position& position, Movement& movement);

    /**
     * Method move()
     * @brief move the piece a the position wit movement and does the attack
     * if there is one
     * create an error if the state is not @bold MOVE_PIECE
     * @param position a Position reference
     * @param movement a Movement reference
     */
    void move (Position& position, Movement& movement, GameType gameType);

    /**
     * Method gameOver()
     * @brief check if the game is done, if no piece can move or if the flag is taken
     * @return a boolean true if the game is done, false instead
     */
    bool gameOver();

    /**
     * Method nextPlayer()
     * @brief change the currentPlayer for the player is waiting
     * create an error if the state is not @bold TURN_END
     */
    void nextPlayer();

    /**
     * Method movementPossibilitiesPiece()
     * @brief call the m_board.movementPossibilities() and put this return
     * to a vector<Movement>
     * @param position a Position by reference
     * @return a vector<Movement> of movement possibilities
     */
    std::vector <Movement> movementPossibilitiesPiece(Position& position);

    /**
     * Method isInside()
     * @brief call the m_board.isInside
     * @param position a Position by reference
     * @return a boolean true if the position is inside the board, fales instead
     */
    bool isInside(Position& position);

    /**
     * Method isFlagCaptured()
     * @brief checks if one of players flag are captured
     * @return a boolean true if there is one, false instead
     */
    bool isFlagCaptured();

    /**
     * Method getWinner()
     * @brief takes the winner of the game
     * create an error if the state is not @bold GAME_OVER
     * @return a String color of the winner
     */
    std::string getWinner();

    /**
     * Method getBoardSize()
     * @brief getter of the board size
     * @return an int of the board size
     */
    int getBoardSize();

    /**
     * Method getBoard()
     * @brief getter of the board
     * @return return a Board by reference
     */
    Board& getBoard();

    /**
     * Method getState()
     * @brief getter if the state
     * @return the current State
     */
    State getState();

    /**
     * Method getCurrentPlayer()
     * @brief getter of the current player
     * @return a Player pointer.
     */
    Player* getCurrentPlayer();

    /**
     * Method getAllPlayers()
     * @brief getter of allPlayers()
     * @return a vector<Player> of players
     */
    std::vector<Player> & getAllPlayers();

    /**
     * Method getAvailable
     * @brief getter of getAvailablePiecesPlayer()
     * @return a vector <Piece> of pieces
     */
    std::vector <Piece> getAvailablePiecesPlayer();

    /**
     * Method canMoveAtLeastOnePiece()
     * @brief checks if at least one piece can be moved
     * @return a boolean true if at least one can be moved, false instead
     */
    bool canMoveAtLeastOnePiece();

    /**
     * Method convertsFileToVector
     * @brief converts a .txt file to  players pieces
     * @param name a String name of the file
     * @param player a player by reference
     */
    void convertsFileToVector (std::string name, Player & player);

    /**
     * Method isOwnPiece()
     * @brief checks if the piece ont the position belongs to the current player
     * @param position a Position by reference
     * @return a boolean true if it belongs to the current player, false instead
     */
    bool isOwnPiece (Position& position);

    /**
     * Method clearBoard()
     * @brief clear the board
     */
    void clearBoard();

};

#endif // GAME_H
