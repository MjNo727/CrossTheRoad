#include"Map.h"
#include "Game.h"

using namespace std;


int main() {
	Game game;
	int temp;
	
	game.ResizeConsole(1366, 768);
	game.FixConsoleWindow();
	
	thread t1(&Game::menu, game);

	t1.join();
	
	return 0;
}