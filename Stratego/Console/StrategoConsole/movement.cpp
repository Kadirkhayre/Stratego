#include "movement.h"

Movement::Movement(Direction direction, int steps):
    m_direction(direction), m_steps(steps){}

int Movement::getSteps()const{
    return m_steps;
}

Direction Movement::getDirection()const{
    return m_direction;
}
