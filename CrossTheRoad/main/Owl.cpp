#include "Owl.h"


Owl::Owl() {
    shape.push_back(" OwlOwlOwlOwlOwl ");
    shape.push_back(" OwlOwlOwlOwlOwl ");
    shape.push_back(" OwlOwlOwlOwlOwl ");

}

Owl::Owl(int x) : Obstacle(x, 0) {
    shape.push_back(" OwlOwlOwlOwlOwl ");
    shape.push_back(" OwlOwlOwlOwlOwl ");
    shape.push_back(" OwlOwlOwlOwlOwl ");
}



int Owl::isForm() {
    return 3;
}

void Owl::sound() {
    PlaySound(TEXT("Sound\\Owl.wav"), NULL, SND_FILENAME | SND_ASYNC);
}