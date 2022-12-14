#include "Game.h"

void GoToXY(int x, int y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void NoCursorType() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void CursorType() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void TextColor(int color) {
	HANDLE hConsoleColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void clrscr() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY,
		//console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void Game::ResizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT edge;
	GetWindowRect(console, &edge);
	MoveWindow(console, edge.left, edge.top, width, height, TRUE);
}

void Game::FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

std::mt19937::result_type getSeed()

{
	std::random_device rd;
	std::mt19937::result_type seed = rd() ^ (
		(std::mt19937::result_type)
		std::chrono::duration_cast<std::chrono::seconds>(
			std::chrono::system_clock::now().time_since_epoch()
			).count() +
		(std::mt19937::result_type)
		std::chrono::duration_cast<std::chrono::microseconds>(
			std::chrono::high_resolution_clock::now().time_since_epoch()
			).count());

	return seed;
}

void Game::logoCrossyRoad() {
	NoCursorType();
	TextColor(240);
	int x = 45;
	int y = 4;
	GoToXY(x - 15, y);		cout << " _______  _______   _______  _______  _______         _______  __   __  _______          _______   _______  _______  ______  " << endl;
	GoToXY(x - 15, y + 1);	cout << "|      _||    _  | |       ||       ||       |       |_     _||  | |  ||  _____|        |    _  | |       ||   _   ||      | " << endl;
	GoToXY(x - 15, y + 2);	cout << "|     |  |   | | | |   _   ||  _____||  _____|         |   |  |  |_|  ||  |____         |   | | | |   _   ||  | |  ||  __   |" << endl;
	GoToXY(x - 15, y + 3);	cout << "|     |  |   |_| | |  | |  || |_____ | |_____          |   |  |   _   ||  _____|        |   |_| | |  | |  ||  |_|  || |  |  |" << endl;
	GoToXY(x - 15, y + 4);	cout << "|     |  |    __  ||  |_|  ||_____  ||_____  |         |   |  |  | |  ||  |____         |    __  ||  |_|  ||   _   || |__|  |" << endl;
	GoToXY(x - 15, y + 5);	cout << "|     |  |   |  | ||       | _____| | _____| |         |___|  |__| |__||_______|        |   |  | ||       ||  | |  ||       |" << endl;
	GoToXY(x - 15, y + 6);	cout << "|_______||___|  |_||_______||_______||_______|                                          |___|  |_||_______||__| |__||______| " << endl;

	GoToXY(x - 23, y - 2);
	for (int i = 0; i < 140; ++i)
		cout << DOWN_BLACK_PIECE;
	GoToXY(x - 20, y - 1);
	for (int i = 0; i < 134; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	GoToXY(x - 20, y + 8);
	for (int i = 0; i < 134; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	GoToXY(x - 23, 13);
	for (int i = 0; i < 140; ++i)
		cout << UP_BLACK_PIECE;

	GoToXY(x - 21, y - 1);
	cout << UP_LEFT_CORNER_PALE_PIECE;
	GoToXY(x - 21, y + 8);
	cout << DOWN_LEFT_CORNER_PALE_PIECE;

	GoToXY(x + 114, y - 1);
	cout << UP_RIGHT_CORNER_PALE_PIECE;
	GoToXY(x + 114, y + 8);
	cout << DOWN_RIGHT_CORNER_PALE_PIECE;

	for (int i = 4; i < 12; ++i) {
		GoToXY(x - 21, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 4; i < 12; ++i) {
		GoToXY(x + 114, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		GoToXY(x - 23, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		GoToXY(x + 116, i);
		cout << VERTICAL_BLACK_PIECE;
	}
}


void Game::fillMenu() {
	TextColor(240);
	for (int i = 18; i < 28; ++i) {
		GoToXY(84, i);
		for (int j = 0; j < 22; ++j) {
			cout << " ";
		}
	}
}


void Game::settings() {
	NoCursorType();
	TextColor(240);
	fillMenu();
	int x = 84;
	int y = 18;
	GoToXY(x + 1, y);
	for (int i = 0; i < 20; ++i)
		cout << UP_BLACK_PIECE;
	for (int i = y; i < y + 7; ++i)
	{
		GoToXY(x, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = y; i < y + 7; ++i)
	{
		GoToXY(x + 21, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	GoToXY(x + 1, y + 6);
	for (int i = 0; i < 20; ++i)
		cout << DOWN_BLACK_PIECE;

	TextColor(240);
	GoToXY(x + 6, y + 1); cout << "MODE:";
	if (mode == true) {
		GoToXY(x + 12, y + 1); cout << "EASY";
	}
	else {
		GoToXY(x + 12, y + 1); cout << "HARD";
	}
	GoToXY(x + 6, y + 3); cout << "SOUND:";
	if (checkMute == false) {
		GoToXY(x + 13, y + 3); cout << "ON";
	}
	else {
		GoToXY(x + 13, y + 3); cout << "OFF";
	}
	GoToXY(x + 9, y + 5); cout << "BACK";

	int cnt = 0;
	while (true)
	{
		char choice = _getch();
		TextColor(240);
		GoToXY(x + 6, y + 1); cout << "MODE:";
		GoToXY(x + 6, y + 3); cout << "SOUND:";
		GoToXY(x + 8, y + 5); cout << " BACK ";

		if (choice == KEY_DOWN || choice == 'S' || choice == 's') {
			cnt++;
			if (cnt > 3)
				cnt = 1;
		}
		if (choice == KEY_UP || choice == 'W' || choice == 'w') {
			cnt--;
			if (cnt < 1)
				cnt = 3;
		}
		if (cnt == 1) {
			TextColor(15);
			GoToXY(x + 6, y + 1); cout << "MODE:";
			if (choice == KEY_ENTER) {
				if (mode == true)
					mode = false;
				else
					mode = true;

				if (mode == true) {
					TextColor(240);
					GoToXY(x + 12, y + 1); cout << "EASY";
				}
				else {
					TextColor(240);
					GoToXY(x + 12, y + 1); cout << "HARD";
				}
			}
		}
		if (cnt == 2) {
			TextColor(15);
			GoToXY(x + 6, y + 3); cout << "SOUND:";
			if (choice == KEY_ENTER) {
				if (checkMute == true)
					checkMute = false;
				else
					checkMute = true;

				if (checkMute == false) {
					TextColor(240);
					GoToXY(x + 13, y + 3); cout << "ON ";
					//PlaySound(TEXT("Sound\\Sister'sNoise.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				}
				else {
					TextColor(240);
					GoToXY(x + 13, y + 3); cout << "OFF";
					//PlaySound(NULL, NULL, SND_ASYNC);
				}
			}
		}
		if (cnt == 3) {
			TextColor(15);
			GoToXY(x + 8, y + 5); cout << " BACK ";
			if (choice == KEY_ENTER) {
				fillMenu();
				GoToXY(x + 1, y);
				for (int i = 0; i < 20; ++i)
					cout << UP_BLACK_PIECE;
				for (int i = y; i < y + 9; ++i)
				{
					GoToXY(x, i);
					cout << VERTICAL_BLACK_PIECE;
				}
				for (int i = y; i < y + 9; ++i)
				{
					GoToXY(x + 21, i);
					cout << VERTICAL_BLACK_PIECE;
				}
				GoToXY(x + 1, y + 8);
				for (int i = 0; i < 20; ++i)
					cout << DOWN_BLACK_PIECE;

				TextColor(240);
				GoToXY(x + 7, y + 1); cout << "NEW GAME";
				GoToXY(x + 6, y + 3); cout << "LOAD  GAME";
				TextColor(15);
				GoToXY(x + 6, y + 5); cout << " SETTINGS ";
				TextColor(240);
				GoToXY(x + 9, y + 7); cout << "EXIT";
				return;
			}
		}
	}
}

void Game::menu() {
	
	while (true) {
		clrscr();
		logoCrossyRoad();
		if (checkMute == false)
			//PlaySound(TEXT("Sound\\Sister'sNoise.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		NoCursorType();
		TextColor(240);
		int x = 84;
		int y = 18;
		GoToXY(x + 1, y);
		for (int i = 0; i < 20; ++i)
			cout << UP_BLACK_PIECE;
		for (int i = y; i < y + 9; ++i)
		{
			GoToXY(x, i);
			cout << VERTICAL_BLACK_PIECE;
		}
		for (int i = y; i < y + 9; ++i)
		{
			GoToXY(x + 21, i);
			cout << VERTICAL_BLACK_PIECE;
		}
		GoToXY(x + 1, y + 8);
		for (int i = 0; i < 20; ++i)
			cout << DOWN_BLACK_PIECE;

		TextColor(240);
		GoToXY(x + 7, y + 1); cout << "NEW GAME";
		GoToXY(x + 6, y + 3); cout << "LOAD  GAME";
		GoToXY(x + 7, y + 5); cout << "SETTINGS";
		GoToXY(x + 9, y + 7); cout << "EXIT";

		int cnt = 0;
		//checkLoadGame = false;
		while (true) {
			char choice = _getch();
			TextColor(240);
			GoToXY(x + 6, y + 1); cout << " NEW GAME ";
			GoToXY(x + 5, y + 3); cout << " LOAD  GAME ";
			GoToXY(x + 6, y + 5); cout << " SETTINGS ";
			GoToXY(x + 8, y + 7); cout << " EXIT ";

			if (choice == KEY_DOWN || choice == 'S' || choice == 's') {
				cnt++;
				if (cnt > 4)
					cnt = 1;
			}
			if (choice == KEY_UP || choice == 'W' || choice == 'w') {
				cnt--;
				if (cnt < 1)
					cnt = 4;
			}
			if (choice == KEY_ESC) {
				clrscr();
				exit(0);
			}

			if (cnt == 1) {
				TextColor(15);
				GoToXY(x + 6, y + 1); cout << " NEW GAME ";
				if (choice == KEY_ENTER) {
				
					TextColor(240);
					newGame();
					break;
				}
			}
			if (cnt == 2) {
				TextColor(15);
				GoToXY(x + 5, y + 3); cout << " LOAD  GAME ";
				if (choice == KEY_ENTER) {
					//loadGame();

					break;
				}
			}
			if (cnt == 3) {
				TextColor(15);
				GoToXY(x + 6, y + 5); cout << " SETTINGS ";
				if (choice == KEY_ENTER) {
					settings();
				}
			}
			if (cnt == 4) {
				TextColor(15);
				GoToXY(x + 8, y + 7); cout << " EXIT ";
				if (choice == KEY_ENTER) {
					TextColor(240);
					clrscr();
					exit(0);
				}
			}
		}
		//while (true) {
		//	if (checkLoadGame == true) {
		//		clrscr();
		//		logoCrossyRoad();
		//		loadingBar();
		//		TextColor(240);
		//		newGame();
		//	}
		//	else
		//		break;
		//}
	}
}


void Game::newGame() {
	NoCursorType();
	TextColor(240);

	if (checkLoadGame == false) {
		map.~Map();
		new(&map) Map();
		//new(&map.level) LEVEL(mode, 1);
	}

	clrscr();
	map.printMap();
	map.drawPlayer();

	if (checkLoadGame == false)
		map.initializeMap();

	//map.initialRender();

	checkLoadGame = false;
	checkPauseGame = false;
	int frameTime = 0;
	int round = 1; //map.level.getLevel();
	TextColor(246);
	GoToXY(142, 8);
	cout << round;
	GoToXY(152, 8);
	if (mode == true)
		cout << "EASY";
	else
		cout << "HARD";
	TextColor(240);

	while (!map.checkEndMap()) {
		if (checkPauseGame == false) {
			if (++frameTime == INT_MAX)
				frameTime = 0;
			//map.generateMap(frameTime);
		}
		else if (checkPauseGame == true) {
			TextColor(12); GoToXY(133, 23); cout << MIDDLE_SMALL_BLACK_PIECE << " PAUSE GAME " << endl;
			TextColor(240);
			GoToXY(134, 25); cout << " RESUME " << endl;
			GoToXY(134, 27); cout << "  EXIT  " << endl;

			int temp = 0;
			while (true) {
				char choice = _getch();
				TextColor(240);
				GoToXY(134, 25); cout << " RESUME " << endl;
				GoToXY(134, 27); cout << "  EXIT  " << endl;

				if (choice == KEY_DOWN || choice == 'S' || choice == 's') {
					temp++;
					if (temp > 2)
						temp = 1;
				}
				if (choice == KEY_UP || choice == 'W' || choice == 'w') {
					temp--;
					if (temp < 1)
						temp = 2;
				}
				if (temp == 1) {
					TextColor(15);
					GoToXY(134, 25); cout << " RESUME " << endl;
					if (choice == KEY_ENTER) {
						checkPauseGame = false;
						TextColor(0);
						GoToXY(133, 23); cout << "             " << endl;
						GoToXY(134, 25); cout << "        " << endl;
						GoToXY(134, 27); cout << "        " << endl;
						TextColor(240);
						break;
					}
				}
				if (temp == 2) {
					TextColor(15);
					GoToXY(134, 27); cout << "  EXIT  " << endl;
					if (choice == KEY_ENTER) {
						checkPauseGame = false;
						TextColor(0);
						GoToXY(133, 23); cout << "             " << endl;
						GoToXY(134, 25); cout << "        " << endl;
						GoToXY(134, 27); cout << "        " << endl;
						TextColor(240);
						return;
					}
				}
			}
		}

		if (_kbhit()) {
			char key = _getch();

			if (key == 'J' || key == 'j') {
				checkPauseGame = true;
				// save game
				//saveGame();
				clrscr();
				map.printMap();
				//map.initialRender();
				TextColor(246);
				GoToXY(142, 8); cout << round;
				GoToXY(152, 8);
				if (mode == true)
					cout << "EASY";
				else
					cout << "HARD";
				TextColor(240);
				checkPauseGame = false;
			}
			if (key == 'L' || key == 'l') {
				checkLoadGame = false;
				checkPauseGame = true;
				// load game
				//loadGame();

				checkPauseGame = false;
				if (checkLoadGame == true)
					return;
				else {
					clrscr();
					map.printMap();
					//map.initialRender();
					TextColor(246);
					GoToXY(142, 8); cout << round;
					GoToXY(152, 8);
					if (mode == true)
						cout << "EASY";
					else
						cout << "HARD";
					TextColor(240);
				}
			}
			if (key == 'p') {
				checkPauseGame = true;
			}

			if (key == 'W' || key == 'w') {
				map.updatePosPlayer('W');
			}
			if (key == 'S' || key == 's') {
				map.updatePosPlayer('S');
			}
			if (key == 'A' || key == 'a') {
				map.updatePosPlayer('A');
			}
			if (key == 'D' || key == 'd') {
				map.updatePosPlayer('D');
			}

			map.drawPlayer();
		}

	}
}
