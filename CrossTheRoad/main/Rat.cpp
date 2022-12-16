#include "Rat.h"


Rat::Rat() {
    shape.push_back(" RATRATRATRATRAT ");
    shape.push_back(" RATRATRATRATRAT ");
    shape.push_back(" RATRATRATRATRAT ");

}

Rat::Rat(int x) : Obstacle(x, 0) {
    shape.push_back(" RATRATRATRATRAT ");
    shape.push_back(" RATRATRATRATRAT ");
    shape.push_back(" RATRATRATRATRAT ");
}




int Rat::isForm() {
    return 1;
}

void Rat::sound() {
    PlaySound(TEXT("Sound\\Rat.wav"), NULL, SND_FILENAME | SND_ASYNC);
}