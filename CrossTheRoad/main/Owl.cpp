#include "Owl.h"


Owl::Owl() {
    shape.push_back("    .___,    ");
    shape.push_back(" ___('v')___ ");
    shape.push_back(" `\"-\\,_,/-\"' ");

}

Owl::Owl(int x) : Obstacle(x, 0) {
    shape.push_back("    .___,    ");
    shape.push_back(" ___('v')___ ");
    shape.push_back(" `\"-\\,_,/-\"' ");
}



int Owl::isForm() {
    return 3;
}

void Owl::sound() {
    PlaySound(TEXT("Sound\\Owl.wav"), NULL, SND_FILENAME | SND_ASYNC);
}