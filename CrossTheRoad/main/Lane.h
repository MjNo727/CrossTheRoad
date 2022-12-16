#pragma once
#include "Library.h"
#include "Obstacle.h"
// first Lane x = 4, y  = 31
class Lane {
private:
    vector<Obstacle*> obstacles;
    int y;
    int speed;
    int redLightRate;
    int greenLightRate;
    short direction;
    bool redLight;
public:
    Lane();
    Lane(short direction, bool redLight, int speed);
    ~Lane();

    void renderTrafficLight();
    int moveObstacle(int frameTime);

    friend class Map;
    friend class Game;
};