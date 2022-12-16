#pragma once
#include "Obstacle.h"

//Starting x position for the Snake is -6
class Snake : public Obstacle
{
public:
    Snake();
    Snake(int x);
    int isForm();
    void sound();

};