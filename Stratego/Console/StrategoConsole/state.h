#ifndef STATE_H
#define STATE_H

/**
 * Enum State
 * @brief This State enum refer to each part of the game
 * NOT_STARTED: the game is beginning and initialize components
 * PREPARE_BOARD: put pieces on the board
 * MOVE_PIECE: the main game, ask to the current player and does the movement and/or the attack, inside a while
 * TURN_END: turn the turn and change the current player, inside a while
 * GAME_OVER: check the winner and show it
 */
enum State {
    NOT_STARTED,
    PREPARE_BOARD,
    MOVE_PIECE,
    TURN_END,
    GAME_OVER
};

#endif // STATE_H
