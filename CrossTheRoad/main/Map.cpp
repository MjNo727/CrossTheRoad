#include "Map.h"
#include "Game.h"

Map::Map() : player()/*, level(), lanes(9)*/ {}

void Map::printMapBorder() {
	TextColor(240);

	for (int i = 0; i < 37; ++i) {
		GoToXY(0, i);	cout << "  ";
		GoToXY(121, i);	cout << "  ";
	}

	GoToXY(3, 0);
	for (int i = 0; i < 117; ++i)
		cout << DOWN_BLACK_PIECE;

	for (int i = 1; i < 37; ++i) {
		GoToXY(119, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = 1; i < 37; ++i) {
		GoToXY(3, i);
		cout << VERTICAL_BLACK_PIECE;
	}

	GoToXY(3, 37);
	for (int i = 0; i < 117; ++i)
		cout << UP_BLACK_PIECE;
}

void Map::printMap() {
	printMapBorder();

	int x = 127;
	int y = 6;
	GoToXY(x, y);
	for (int i = 0; i < 35; ++i)
		cout << DOWN_BLACK_PIECE;
	for (int i = 7; i < 21; ++i) {
		GoToXY(x, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = 7; i < 21; ++i) {
		GoToXY(x + 34, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	GoToXY(x, y + 15);
	for (int i = 0; i < 35; ++i)
		cout << UP_BLACK_PIECE;

	TextColor(246);
	GoToXY(x + 6, y + 2); cout << MIDDLE_SMALL_BLACK_PIECE << " ROUND: ";
	GoToXY(x + 17, y + 2); cout << "| MODE: ";

	TextColor(246);	GoToXY(x + 6, y + 4); cout << MIDDLE_SMALL_BLACK_PIECE << " MOVING KEYBOARD " << endl;
	TextColor(244);
	GoToXY(x + 8, 11); cout << "W: UP" << endl;
	GoToXY(x + 8, 12); cout << "S: DOWN" << endl;
	GoToXY(x + 8, 13); cout << "A: LEFT" << endl;
	GoToXY(x + 8, 14); cout << "D: RIGHT" << endl;

	TextColor(246); GoToXY(x + 6, y + 10); cout << MIDDLE_SMALL_BLACK_PIECE << " COMMAND KEYBOARD " << endl;
	TextColor(244);
	GoToXY(x + 8, 17); cout << "J: SAVE GAME" << endl;
	GoToXY(x + 8, 18); cout << "L: LOAD GAME" << endl;
	GoToXY(x + 8, 19); cout << "P: PAUSE GAME" << endl;
}

void Map::fillInsideMap() {
	TextColor(240);
	for (int i = 1; i < 37; ++i) {
		GoToXY(4, i);
		for (int j = 0; j < 115; ++j) {
			cout << " ";
		}
	}
}

int Map::drawFromPosition(int x, int y, vector<string>shape, int w, int h) {
	TextColor(240);

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			GoToXY(x + j, y + i);
			cout << shape[i][j];
		}
	}
	return 1;
}

void Map::drawPlayer() {
	int live = drawFromPosition(player.getX(), player.getY(), player.getPeople(), player.getWidth(), player.getHeight());
	if (live == -1)
		player.setCheckDead();
}

void Map::resetPlayer() {
	drawFromPosition(player.getX(), player.getY(), player.getBlank(), player.getWidth(), player.getHeight());
}

void Map::updatePosPlayer(char key) {
	resetPlayer();

	if (key == 'W' || key == 'w')
		player.Up();
	else if (key == 'S' || key == 's')
		player.Down();
	else if (key == 'A' || key == 'a')
		player.Left();
	else if (key == 'D' || key == 'd')
		player.Right();
	else
		return;
}

bool Map::checkEndMap() {
	return player.getCheckDead();
}
//
void Map::initializeMap()
{
	player.~People ();
	new (&player) People();
	
}

bool Map::checkWin() {
	if (player.getY() == 4)
		return true;
	return false;
}
