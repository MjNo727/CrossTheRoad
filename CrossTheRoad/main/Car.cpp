#include "Car.h"

Car::Car()
{
    shape.push_back(" sssssssssssss ");
    shape.push_back(" sssssssssssss ");

    shape.push_back(" sssssssssssss ");
}

Car::Car(int x) : Obstacle(x, 1)
{
    shape.push_back(" sssssssssssss ");
    shape.push_back(" sssssssssssss ");

    shape.push_back(" sssssssssssss ");
}


int Car::isForm() {
    return 2;
}

void Car::sound() {
    PlaySound(TEXT("Sound\\Car.wav"), NULL, SND_FILENAME | SND_ASYNC);
}