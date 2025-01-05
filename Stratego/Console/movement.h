#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "direction.h"
#include <vector>

/**
 * @brief The Movement class
 */
class Movement{

private:
    Direction m_direction;
    int m_steps;
public:
    /**
     * Constructor
     * @brief Constructor of Movement
     * @param direction the given direction
     * @param steps the given steps, default step is 1.
     */
    Movement(Direction direction, int steps = 1);

    /**
     * Method getSteps()
     * @brief getter of m_steps
     * @return an int of steps
     */
    int getSteps()const;

    /**
     * Method getDirection()
     * @brief getter of m_direction
     * @return a Direction
     */
    Direction getDirection()const;
};

#endif // MOVEMENT_H
