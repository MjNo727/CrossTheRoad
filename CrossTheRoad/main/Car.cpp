<<<<<<< Updated upstream
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
=======
#include"Car.h"

Car::Car()
{
    shape[0] = new char[12]{ ' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' ', ' ', ' ' };
    shape[1] = new char[12]{ ' ', ' ', '_', '/', ' ', ' ', 'L', '\\', '_', '_', ' ' };
    shape[2] = new char[12]{ ' ', '\'', '=', 'o', '-', '-', '-', '-', 'o', '-', '\'' };
}

Car::Car(int x) : ENEMY(x, 1)
{
    shape[0] = new char[12]{ ' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' ', ' ', ' ' };
    shape[1] = new char[12]{ ' ', ' ', '_', '/', ' ', ' ', 'L', '\\', '_', '_', ' ' };
    shape[2] = new char[12]{ ' ', '\'', '=', 'o', '-', '-', '-', '-', 'o', '-', '\'' };
}

void Car::sound() {
    PlaySound(TEXT("Sound\\Car.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
int Car::isWhat() {
>>>>>>> Stashed changes
    return 2;
}