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