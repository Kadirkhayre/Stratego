#ifndef GAME_H
#define GAME_H
#include "position.h"
#include <iostream>
#include <QLayout>
#include "square.h"

/**
 * @brief The Game class
 */
class Game
{
public:
    /**
     * Constructor
     * @brief Constructor of Game
     */
    Game();

    /**
     * Method isnbrWalkOk()
     * @brief Check nbrWalks
     * @param from the given position
     * @param to the given position
     * @param symbol the given symbol
     * @return true if the number of walks is correct, otherwise false
     */
    bool isnbrWalkOk(Position from, Position to, std::string symbol);

    /**
     * isNotALake()
     * @brief Check if there is no lake
     * @param from the given position
     * @param to the given position
     * @param layout the given layout
     * @return true if there is no lake, otherwise false
     */
    bool isNotALake(Position from, Position to, QLayout* layout);

    /**
     * moveAttackNull()
     * @brief Check if the pieces are same
     * @param from the given position
     * @param to the given position
     * @param layout the given layout
     * @return true if the attack works, otherwise false
     */
    bool moveAttackNull(Position& from, Position& to, QLayout* layout);
    /**
     * moveAttackOk()
     * @brief Check if the attack is ok
     * @param from the given position
     * @param to the given position
     * @param layout the given layout
     * @return true if the attack works, otherwise false
     */
    bool moveAttackOk(Position& from, Position& to, QLayout* layout);
    /**
     * movAttackFail()
     * @brief moveAttackFail
     * @param Check if the attack fails
     * @param to the given position
     * @param layout the given layout
     * @return true if the attack fails, otherwise false
     */
    bool moveAttackFail(Position& from, Position& to, QLayout* layout);

private:
    /**
     * Method isOneStep()
     * @brief Check if is one step
     * @param from the given position
     * @param to the given position
     * @return true if is one step, otherwise false
     */
    bool isOneStep(Position from, Position to);

    /**
     * Method isOnSameLine()
     * @brief Check if is one same line
     * @param from the given position
     * @param to the given position
     * @return true if is one same line, otherwise
     */
    bool isOnSameLine(Position from, Position to);

};

#endif // GAME_H
