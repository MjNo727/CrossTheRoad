#pragma once

#include "Library.h"
#include "Obstacle.h"

class Level
{
private:
    int level;
    int maxObstacle, currObstacle;
    int minSpeed, maxSpeed;
    bool mode;
    const int maxLevel = 5;

    void generateLevel();

public:
    Level(bool mode = 1, int level = 1);
    Level(bool mode, int level, int currObstacle);
    ~Level() {};
    bool newLevel(int lv);
    bool nextLevel();
    Obstacle* randNewObstacle(int x, short direction);
    int getLevel();

    friend class Lane;
    friend class Map;

};
