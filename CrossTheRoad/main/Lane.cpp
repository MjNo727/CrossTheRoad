#include "Lane.h"
#include "Game.h"

Lane::Lane() : direction(1), redLight(0), speed(1) {}

Lane::Lane(short direction, bool redLight, int speed) : direction(direction), redLight(redLight), speed(speed) {}

Lane::~Lane()
{
    for (Obstacle* Obstacle : obstacles)
        delete Obstacle;
}

void Lane::renderTrafficLight()
{
    TextColor(redLight ? 12 : 10);
    GoToXY(direction == 1 ? 121 : 0, y + 1);

    cout << VERTICAL_BLACK_PIECE << VERTICAL_BLACK_PIECE;
    TextColor(7);
}

int Lane::moveObstacle(int frameTime)
{
    int outOfMap = 0;

    if ((redLight && frameTime % greenLightRate == 0) || (!redLight && frameTime % redLightRate == 0))
    {
        redLight = !redLight;
        renderTrafficLight();
    }

    if (redLight)
        return 0;

    if (frameTime % speed != 0)
        return 0;

    for (int i = 0; i < obstacles.size(); ++i)
    {
        obstacles[i]->mX += direction;
        if (obstacles[i]->checkOut())
        {
            obstacles.erase(obstacles.begin() + i);
            ++outOfMap;
        }
        else
            obstacles[i]->renderShape(y);
    }

    return outOfMap;
}