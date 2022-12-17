#include "Truck.h"


Truck::Truck() {
    shape.push_back("  ___//_]\\___  ");
    shape.push_back(" |o _ | -|_o )  ");
    shape.push_back(" `(o)---(o)--'  ");

}

Truck::Truck(int x) : Obstacle(x, 1) {
    shape.push_back("  ___//_]\\___  ");
    shape.push_back(" |o _ | -|_o )  ");
    shape.push_back(" `(o)---(o)--'  ");
}




int Truck::isForm() {
    return 5;
}

void Truck::sound() {
    PlaySound(TEXT("Sound\\Car.wav"), NULL, SND_FILENAME | SND_ASYNC);
}