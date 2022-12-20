#include"Map.h"
#include "Game.h"

using namespace std;

int main() {
	Game game;
	
	game.ResizeConsole(1280, 720);
	game.FixConsoleWindow();
	thread t1(&Game::menu, game);
	t1.join();
	
	return 0;
}