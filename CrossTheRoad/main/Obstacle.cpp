#include "Obstacle.h"
#include "Game.h"
Obstacle::Obstacle() {
	int mX = 0;
	this->form = 1;
}
Obstacle::Obstacle(int x, bool form) : mX(x), form(form) {

}
void Obstacle::renderShape(int y)
{
	TextColor(240);
	int leftMost = mX < LEFT_BORDER ? LEFT_BORDER - mX : 0;

	int pos = mX < LEFT_BORDER ? LEFT_BORDER : mX;

	int rightMost = mX + shape[0].length() > RIGHT_BORDER ? RIGHT_BORDER - mX + 1 : shape[0].length() + 1;
	if (leftMost >= rightMost) {
		return;
	}
	for (int i = 0; i < 3; ++i)
	{
		GoToXY(pos, y + i);
		for (int j = leftMost; j < rightMost; ++j)
		{

			cout << shape[i][j];
		}
	}
}
bool Obstacle::checkOut() {
	return mX < -13 || mX>123;
}
bool Obstacle::checkSpawn() {
	return mX < 7 || mX > 100;
}
