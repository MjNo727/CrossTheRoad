#include "Snake.h"


Snake::Snake() {
    shape.push_back("    __    --_- ");
    shape.push_back(" >~8_ |__/ /   ");
    shape.push_back("    |_____/    ");

}

Snake::Snake(int x) : Obstacle(x, 0) {
    shape.push_back("    __    --_- ");
    shape.push_back(" >~8_ |__/ /   ");
    shape.push_back("    |_____/    ");
}




int Snake::isForm() {
    return 4;
}

void Snake::sound() {
    PlaySound(TEXT("Sound\\Snake.wav"), NULL, SND_FILENAME | SND_ASYNC);
}