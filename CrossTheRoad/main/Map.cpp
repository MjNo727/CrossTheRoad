#include "Map.h"
#include "Game.h"

Map::Map() : player(), level(), lanes(9) {}

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

int Map::renderMAP(int frameTime)
{
	int outOfMap = 0;

	for (Lane& lane : lanes)
		outOfMap += lane.moveObstacle(frameTime);

	return outOfMap;
}

bool Map::checkCollision()
{
	for (Lane& lane : lanes)
	{
		for (Obstacle*& obstacle : lane.obstacles)
		{
			if (player.getY() == lane.y && player.checkCollision(*obstacle))
				return true;
		}
	}

	return false;
}

void Map::initializeMap()
{
	player.~People();
	new (&player) People();
	lanes.clear();

	std::mt19937 rng(getSeed());
	std::uniform_int_distribution<unsigned> ZeroOne(0, 1);
	std::uniform_int_distribution<unsigned> Speed(level.maxSpeed, level.minSpeed);
	std::uniform_int_distribution<unsigned> Steps(60, 80);

	switch (level.level)
	{
	case 1:
		lanes = vector<Lane>(5);

		for (int i = 0; i < 5; ++i)
		{
			lanes[i].y = i * 6 + 7;
			lanes[i].speed = Speed(rng);
			lanes[i].redLightRate = lanes[i].speed * Steps(rng);
			lanes[i].greenLightRate = lanes[i].speed * Steps(rng);
			lanes[i].direction = ZeroOne(rng) ? 1 : -1;
			lanes[i].redLight = ZeroOne(rng);
		}

		break;

	case 2:
		lanes = vector<Lane>(6);

		for (int i = 0; i < 6; ++i)
		{
			if (i < 3)
				lanes[i].y = i * 3 + 7;
			else
				lanes[i].y = lanes[i - 1].y + 6;

			lanes[i].speed = Speed(rng);
			lanes[i].redLightRate = lanes[i].speed * Steps(rng);
			lanes[i].greenLightRate = lanes[i].speed * Steps(rng);
			lanes[i].direction = ZeroOne(rng) ? 1 : -1;
			lanes[i].redLight = ZeroOne(rng);
		}

		break;

	case 3:
		lanes = vector<Lane>(7);

		for (int i = 0; i < 7; ++i)
		{
			if (i < 5)
				lanes[i].y = i * 3 + 7;
			else
				lanes[i].y = lanes[i - 1].y + 6;

			lanes[i].speed = Speed(rng);
			lanes[i].redLightRate = lanes[i].speed * Steps(rng);
			lanes[i].greenLightRate = lanes[i].speed * Steps(rng);
			lanes[i].direction = ZeroOne(rng) ? 1 : -1;
			lanes[i].redLight = ZeroOne(rng);
		}

		break;

	case 4:
		lanes = vector<Lane>(8);

		for (int i = 0; i < 8; ++i)
		{
			if (i < 7)
				lanes[i].y = i * 3 + 7;
			else
				lanes[i].y = lanes[i - 1].y + 6;

			lanes[i].speed = Speed(rng);
			lanes[i].redLightRate = lanes[i].speed * Steps(rng);
			lanes[i].greenLightRate = lanes[i].speed * Steps(rng);
			lanes[i].direction = ZeroOne(rng) ? 1 : -1;
			lanes[i].redLight = ZeroOne(rng);
		}

		break;

	default:
		lanes = vector<Lane>(9);

		for (int i = 0; i < 9; ++i)
		{
			lanes[i].y = i * 3 + 7;
			lanes[i].speed = Speed(rng);
			lanes[i].redLightRate = lanes[i].speed * Steps(rng);
			lanes[i].greenLightRate = lanes[i].speed * Steps(rng);
			lanes[i].direction = ZeroOne(rng) ? 1 : -1;
			lanes[i].redLight = ZeroOne(rng);
		}

		break;
	}

	std::uniform_int_distribution<unsigned> Row(0, lanes.size() - 1);
	std::uniform_int_distribution<unsigned> Pos(LEFT_BORDER, RIGHT_BORDER);
	std::uniform_int_distribution<unsigned> distance(25, 30);

	int xPos[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	Obstacle* newEnemy;
	while (level.currObstacle < level.maxObstacle)
	{
		int row = Row(rng);

		if (xPos[row] == 0)
			xPos[row] += Pos(rng);
		else
			xPos[row] += distance(rng);

		newEnemy = level.randNewObstacle(xPos[row], lanes[row].direction);

		if (newEnemy)
			lanes[row].obstacles.push_back(newEnemy);
	}
}
void Map::initialRender()
{
	for (Lane& Lane : lanes)
	{
		Lane.renderTrafficLight();
		for (Obstacle*& Obstacle : Lane.obstacles)
			Obstacle->renderShape(Lane.y);
	}
}

void Map::generateMap(int frameTime)
{
	std::mt19937 rng(getSeed());
	std::uniform_int_distribution<unsigned> Row(0, lanes.size() - 1);
	std::uniform_int_distribution<unsigned> Pos(LEFT_BORDER, RIGHT_BORDER);


	Obstacle* newEnemy;
	int fails = 0;
	while (level.currObstacle < level.maxObstacle)
	{
		int row = Row(rng);

		if (lanes[row].obstacles.empty() || !lanes[row].obstacles.back()->checkSpawn())
		{
			int xPos = lanes[row].direction == 1 ? -10 : 120;
			newEnemy = level.randNewObstacle(xPos, lanes[row].direction);

			if (newEnemy)
				lanes[row].obstacles.push_back(newEnemy);
		}
		else
			if (++fails > lanes.size())
				break;

	}

	level.currObstacle -= renderMAP(frameTime);
}

void Map::levelUp() {
	level.nextLevel();
}

bool Map::checkMaxLevel() {
	if (level.getLevel() == 5)
		return true;
	return false;
}

bool Map::checkWin() {
	if (player.getY() == 4)
		return true;
	return false;
}
