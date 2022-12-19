#include "Level.h"
#include "Game.h"

Level::Level(bool mode, int level) : mode(mode), level(level), currObstacle(0)
{
    generateLevel();
}

Level::Level(bool mode, int level, int currObstacle) : mode(mode), level(level), currObstacle(currObstacle) {
    generateLevel();
}

void Level::generateLevel() {
    if (mode)
        switch (level)
        {
        case 1:
            maxObstacle = 10;
            minSpeed = 1400;
            maxSpeed = 1000;
            break;

        case 2:
            maxObstacle = 13;
            minSpeed = 1400;
            maxSpeed = 1000;
            break;

        case 3:
            maxObstacle = 15;
            minSpeed = 1200;
            maxSpeed = 800;
            break;

        case 4:
            maxObstacle = 15;
            minSpeed = 1000;
            maxSpeed = 600;
            break;

        default:
            maxObstacle = 17;
            minSpeed = 1000;
            maxSpeed = 600;
            break;
        }
    else
        switch (level)
        {
        case 1:
            maxObstacle = 17;
            minSpeed = 1000;
            maxSpeed = 600;
            break;

        case 2:
            maxObstacle = 20;
            minSpeed = 800;
            maxSpeed = 400;
            break;

        case 3:
            maxObstacle = 23;
            minSpeed = 800;
            maxSpeed = 400;
            break;

        case 4:
            maxObstacle = 25;
            minSpeed = 800;
            maxSpeed = 400;
            break;

        default:
            maxObstacle = 28;
            minSpeed = 700;
            maxSpeed = 300;
            break;
        }
}

bool Level::newLevel(int lv) {
    if (lv > maxLevel) return false;
    level = lv;
    currObstacle = 0;
    generateLevel();
    return true;
}

bool Level::nextLevel() {
    if (level == maxLevel) return false;
    ++level;
    currObstacle = 0;
    return true;
}

Obstacle* Level::randNewObstacle(int x, short direction) {
    if (currObstacle == maxObstacle)
        return NULL;

    if (currObstacle < (maxObstacle)) {
        ++currObstacle;
        Obstacle* Obstacle = NULL;

        std::mt19937 rng(getSeed());
        std::uniform_int_distribution<unsigned> Vehicle(0, 2);
        std::uniform_int_distribution<unsigned> Animal(0, 3);
        // Animal = 0, Vehicle = 1
        if (direction == 1) {
            if (Vehicle(rng))
                Obstacle = new Car(x);

            else
                Obstacle = new Truck(x);

        }
        else {
            switch (Animal(rng))
            {
            case 0:
                Obstacle = new Owl(x);
                break;

            case 1:
                Obstacle = new Rat(x);
                break;

            default:
                Obstacle = new Snake(x);
                break;
            }
        }

        return Obstacle;
    }

    return NULL;
}
int Level::getLevel() {
    return level;
}