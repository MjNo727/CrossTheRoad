#include "people.h"

People::People() {
	checkDead = false;
	x = 60;
	y = 34;

	createPeople();
}

People::People(int x, int y) {
	checkDead = false;

	createBlank();
	createPeople();
}




void People::createBlank() {
	for (int i = 0; i < 3; ++i) {
		blank.push_back("     ");
	}
}
void People::createPeople() {
	createBlank();
	// Head
	people.push_back(" abc ");


	// Body
	people.push_back(" bcd ");


	// Legs
	people.push_back(" efg ");

}

int People::getHeight() {
	return height;
}

int People::getWidth() {
	return width;
}

int People::getX() {
	return x;
}

int People::getY() {
	return y;
}

void People::Up() {
	if (getY() <= 3)
		return;
	y = y - 3;
}

void People::Down() {
	if (getY() + 3 >= 37)
		return;
	y = y + 3;
}

void People::Left() {
	if (getX() <= LEFT_MAP)
		return;
	x = x - 2;
}

void People::Right() {
	if (getX() >= RIGHT_MAP)
		return;
	x = x + 2;
}

vector<string> People::getPeople() {
	return people;
}
vector<string>People::getBlank() {
	return blank;
}



void People::setCheckDead() {
	checkDead = true;
}
bool People::getCheckDead() {
	return checkDead;
}
//
//bool People::checkCollision(ENEMY& enemy) {
//
//	int length = enemy.shape[0].length();
//
//	if ((enemy.x + enemy.type <= x && x <= enemy.x + enemy.type + length - 2) || (enemy.x + enemy.type <= x + 4 && x + 4 <= enemy.x + enemy.type + length - 2))
//	{
//		enemy.sound();
//		return true;
//	}
//
//
//
//	return false;
//}
