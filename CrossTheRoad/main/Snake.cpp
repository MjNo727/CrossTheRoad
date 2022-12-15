#include "Snake.h"


Snake::Snake() {
    shape.push_back(" SnakeSnakeSna ");
    shape.push_back(" SnakeSnakeSna ");
    shape.push_back(" SnakeSnakeSna ");

}

Snake::Snake(int x) : Obstacle(x, 0) {
    shape.push_back(" SnakeSnakeSna ");
    shape.push_back(" SnakeSnakeSna ");
    shape.push_back(" SnakeSnakeSna ");
}




int Snake::isForm() {
    return 4;
}