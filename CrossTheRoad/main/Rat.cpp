#include "Rat.h"


Rat::Rat() {
    shape.push_back(" ()-()_----_ ");
    shape.push_back("  \\\"/` ___  ; ");
    shape.push_back("   ` ^^   ^^  ");

}

Rat::Rat(int x) : Obstacle(x, 0) {
    shape.push_back(" ()-()_----_ ");
    shape.push_back("  \\\"/` ___  ; ");
    shape.push_back("   ` ^^   ^^  ");
}




int Rat::isForm() {
    return 1;
}

void Rat::sound() {
    PlaySound(TEXT("Sound\\Rat.wav"), NULL, SND_FILENAME | SND_ASYNC);
}