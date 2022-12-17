#include "Car.h"

Car::Car()
{
    shape.push_back("      _   ");
    shape.push_back(" _-_-_=\\-_ ");
    shape.push_back(" (o)=='(o) ");
}

Car::Car(int x) : Obstacle(x, 1)
{
    shape.push_back("      _   ");
    shape.push_back(" _-_-_=\\-_ ");
    shape.push_back(" (o)=='(o) ");
}


int Car::isForm() {
    return 2;
}

void Car::sound() {
    PlaySound(TEXT("Sound\\Car.wav"), NULL, SND_FILENAME | SND_ASYNC);
}