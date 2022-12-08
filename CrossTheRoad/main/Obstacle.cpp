#include "Obstacle.h"
#include "Game.h"
void Obstacle::renderShape(int y)
{
	int leftMost = 0;
	int pos = mX;
	if (mX < LEFT_BORDER) {
		leftMost = LEFT_BORDER - mX;
		pos = LEFT_BORDER;
	}
	int rightMost = shape[0].length() + 1;
	if (mX + shape[0].length() > RIGHT_BORDER) {
		rightMost = RIGHT_BORDER - mX + 1;
	}
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
