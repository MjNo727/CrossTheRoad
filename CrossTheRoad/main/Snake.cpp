#include "Snake.h"


Snake::Snake() {
    shape.push_back("SnakeSnakeSnakeSnakeSnake ");
    shape.push_back("SnakeSnakeSnakeSnakeSnake ");
    shape.push_back("SnakeSnakeSnakeSnakeSnake ");

}

Snake::Snake(int x) : Obstacle(x, 0) {
    shape.push_back("SnakeSnakeSnakeSnakeSnake ");
    shape.push_back("SnakeSnakeSnakeSnakeSnake ");
    shape.push_back("SnakeSnakeSnakeSnakeSnake ");
}




int Snake::isForm() {
    return 4;
}