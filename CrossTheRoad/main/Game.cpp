#include "Game.h"
void GoToXY(int x, int y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void NoCursor() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void Cursor() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void TextColor(int color) {
	HANDLE hConsoleColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void TextColor(WORD color) {
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

void Game::CRLogo() {
	NoCursor();
	TextColor(240);
	int x = 45;
	int y = 4;
	GoToXY(x - 15, y);		cout << "         ____                                     ______  __                  ____                         __     " << endl;
	GoToXY(x - 15, y + 1);	cout << "        /\\  _`\\                                  /\\__  _\\/\\ \\                /\\  _`\\                      /\\ \\    " << endl;
	GoToXY(x - 15, y + 2);	cout << "        \\ \\ \\/\\_\\  _ __   ___     ____    ____   \\/_/\\ \\/\\ \\ \\___      __    \\ \\ \\L\\ \\    ___      __     \\_\\ \\   " << endl;
	GoToXY(x - 15, y + 3);	cout << "         \\ \\ \\/_/_/\\`'__\\/ __`\\  /',__\\  /',__\\     \\ \\ \\ \\ \\  _ `\\  /'__`\\   \\ \\ ,  /   / __`\\  /'__`\\   /'_` \\  " << endl;
	GoToXY(x - 15, y + 4);	cout << "          \\ \\ \\L\\ \\ \\ \\//\\ \\L\\ \\/\\__, `\\/\\__, `\\     \\ \\ \\ \\ \\ \\ \\ \\/\\  __/    \\ \\ \\\\ \\ /\\ \\L\\ \\/\\ \\L\\.\\_/\\ \\L\\ \\ " << endl;
	GoToXY(x - 15, y + 5);	cout << "           \\ \\____/\\ \\_\\\\ \\____/\\/\\____/\\/\\____/      \\ \\_\\ \\ \\_\\ \\_\\ \\____\\    \\ \\_\\ \\_\\ \\____/\\ \\__/.\\_\\ \\___,_\\" << endl;
	GoToXY(x - 15, y + 6);	cout << "            \\/___/  \\/_/ \\/___/  \\/___/  \\/___/        \\/_/  \\/_/\\/_/\\/____/     \\/_/\\/ /\\/___/  \\/__/\\/_/\\/__,_ /" << endl;

	GoToXY(x - 45, y + 11);
	for (int i = 0; i < 172; ++i)
		cout << DOWN_BLACK_PIECE;
	GoToXY(x - 45, y + 24);
	for (int i = 0; i < 172; ++i)
		cout << DOWN_BLACK_PIECE;

	GoToXY(x - 45, y + 17);
	for (int i = 0; i < 140; i++)
	{
		if ((i % 5) != 0) cout << UP_BLACK_PIECE;
		else cout << "  ";
	}
	GoToXY(x - 45, y + 16);
	for (int i = 0; i < 140; i++)
	{
		if ((i % 5) != 0) cout << DOWN_BLACK_PIECE;
		else cout << "  ";
	}
	GoToXY(x + 40, y + 17);
	for (int i = 0; i < 20; i++)
	{
		cout << " ";
	}
	GoToXY(x + 40, y + 16);
	for (int i = 0; i < 20; i++)
	{
		cout << " ";
	}

	GoToXY(x - 20, y + 13);	cout << "                   _..-------++._" << endl;
	GoToXY(x - 20, y + 14);	cout << "               _.-'/ |      _||  \\\"--._" << endl;
	GoToXY(x - 20, y + 15);	cout << "         __.--'`._/_\\j_____/_||___\\    `----." << endl;
	GoToXY(x - 20, y + 16);	cout << "    _.--'_____    |          \\     _____    /" << endl;
	GoToXY(x - 20, y + 17);	cout << "   _j    /,---.\   |        =o |   /,---.\\   |_" << endl;
	GoToXY(x - 20, y + 18);	cout << " [__]==// .-. \\\\==`===========/==// .-. \\\\=[__]" << endl;
	GoToXY(x - 20, y + 19);	cout << "   `-._|\\ `-' /|___\\_________/___|\\ `-' /|_.'    ";
	GoToXY(x - 20, y + 20);	cout << "         `---'                     `---'";

	GoToXY(x + 70, y + 13);	cout << "                   _..-------++._" << endl;
	GoToXY(x + 70, y + 14);	cout << "               _.-'/ |      _||  \\\"--._" << endl;
	GoToXY(x + 70, y + 15);	cout << "         __.--'`._/_\\j_____/_||___\\    `----." << endl;
	GoToXY(x + 70, y + 16);	cout << "    _.--'_____    |          \\     _____    /" << endl;
	GoToXY(x + 70, y + 17);	cout << "   _j    /,---.\   |        =o |   /,---.\\   |_" << endl;
	GoToXY(x + 70, y + 18);	cout << " [__]==// .-. \\\\==`===========/==// .-. \\\\=[__]" << endl;
	GoToXY(x + 70, y + 19);	cout << "   `-._|\\ `-' /|___\\_________/___|\\ `-' /|_.'    ";
	GoToXY(x + 70, y + 20);	cout << "         `---'                     `---'";



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

void Game::logoLoadGame() {
	NoCursor();
	TextColor(240);
	clrscr();
	int x = 45;
	int y = 4;

	GoToXY(x - 2, y);		cout << " ___      _______  _______  ______   ___   __    _  _______    _______  _______  __   __  _______ " << endl;
	GoToXY(x - 2, y + 1);	cout << "|   |    |       ||   _   ||      | |   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |" << endl;
	GoToXY(x - 2, y + 2);	cout << "|   |    |   _   ||  |_|  ||  _    ||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|" << endl;
	GoToXY(x - 2, y + 3);	cout << "|   |    |  | |  ||       || | |   ||   | |       ||   | __   |   | __ |       ||       ||   |___ " << endl;
	GoToXY(x - 2, y + 4);	cout << "|   |___ |  |_|  ||       || |_|   ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|" << endl;
	GoToXY(x - 2, y + 5);	cout << "|       ||       ||   _   ||       ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ " << endl;
	GoToXY(x - 2, y + 6);	cout << "|_______||_______||__| |__||______| |___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|" << endl;

	GoToXY(x - 8, y - 2);
	for (int i = 0; i < 110; ++i)
		cout << DOWN_BLACK_PIECE;
	GoToXY(x - 5, y - 1);
	for (int i = 0; i < 105; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	GoToXY(x - 5, y + 8);
	for (int i = 0; i < 105; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	GoToXY(x - 8, 13);
	for (int i = 0; i < 110; ++i)
		cout << UP_BLACK_PIECE;

	GoToXY(x - 6, y - 1);
	cout << UP_LEFT_CORNER_PALE_PIECE;
	GoToXY(x - 6, y + 8);
	cout << DOWN_LEFT_CORNER_PALE_PIECE;

	GoToXY(x + 99, y - 1);
	cout << UP_RIGHT_CORNER_PALE_PIECE;
	GoToXY(x + 99, y + 8);
	cout << DOWN_RIGHT_CORNER_PALE_PIECE;

	for (int i = 4; i < 12; ++i) {
		GoToXY(x - 6, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 4; i < 12; ++i) {
		GoToXY(x + 99, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		GoToXY(x - 8, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		GoToXY(x + 101, i);
		cout << VERTICAL_BLACK_PIECE;
	}
}

void Game::logoSaveGame() {
	NoCursor();
	TextColor(240);
	clrscr();
	int x = 59;
	int y = 4;

	GoToXY(x - 2, y);		cout << " _______  _______  __   __  _______    _______  _______  __   __  _______ " << endl;
	GoToXY(x - 2, y + 1);	cout << "|       ||   _   ||  | |  ||       |  |       ||   _   ||  |_|  ||       |" << endl;
	GoToXY(x - 2, y + 2);	cout << "|  _____||  |_|  ||  |_|  ||    ___|  |    ___||  |_|  ||       ||    ___|" << endl;
	GoToXY(x - 2, y + 3);	cout << "| |_____ |       ||       ||   |___   |   | __ |       ||       ||   |___ " << endl;
	GoToXY(x - 2, y + 4);	cout << "|_____  ||       ||       ||    ___|  |   ||  ||       ||       ||    ___|" << endl;
	GoToXY(x - 2, y + 5);	cout << " _____| ||   _   | |     | |   |___   |   |_| ||   _   || ||_|| ||   |___ " << endl;
	GoToXY(x - 2, y + 6);	cout << "|_______||__| |__|  |___|  |_______|  |_______||__| |__||_|   |_||_______|" << endl;

	GoToXY(x - 8, y - 2);
	for (int i = 0; i < 86; ++i)
		cout << DOWN_BLACK_PIECE;
	GoToXY(x - 5, y - 1);
	for (int i = 0; i < 81; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	GoToXY(x - 5, y + 8);
	for (int i = 0; i < 81; ++i)
		cout << HORIZONTAL_PALE_PIECE;
	GoToXY(x - 8, 13);
	for (int i = 0; i < 86; ++i)
		cout << UP_BLACK_PIECE;

	GoToXY(x - 6, y - 1);
	cout << UP_LEFT_CORNER_PALE_PIECE;
	GoToXY(x - 6, y + 8);
	cout << DOWN_LEFT_CORNER_PALE_PIECE;

	GoToXY(x + 75, y - 1);
	cout << UP_RIGHT_CORNER_PALE_PIECE;
	GoToXY(x + 75, y + 8);
	cout << DOWN_RIGHT_CORNER_PALE_PIECE;

	for (int i = 4; i < 12; ++i) {
		GoToXY(x - 6, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 4; i < 12; ++i) {
		GoToXY(x + 75, i);
		cout << VERTICAL_PALE_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		GoToXY(x - 8, i);
		cout << VERTICAL_BLACK_PIECE;
	}
	for (int i = 3; i < 13; ++i) {
		GoToXY(x + 77, i);
		cout << VERTICAL_BLACK_PIECE;
	}
}

void Game::loseLogo() {
	TextColor(240);

	NoCursor();
	int x = 53;
	int y = 11;
	int z = 2;

	GoToXY(x, z);		cout << " __   __  _______  __   __    ___      _______  _______  _______    __   __   __ " << endl;
	GoToXY(x, z + 1);	cout << "|  | |  ||       ||  | |  |  |   |    |       ||       ||       |  |  | |  | |  |" << endl;
	GoToXY(x, z + 2);	cout << "|  |_|  ||   _   ||  | |  |  |   |    |   _   ||  _____||_     _|  |  | |  | |  |" << endl;
	GoToXY(x, z + 3);	cout << "|       ||  | |  ||  |_|  |  |   |    |  | |  || |_____   |   |    |  | |  | |  |" << endl;
	GoToXY(x, z + 4);	cout << "|_     _||  |_|  ||       |  |   |___ |  |_|  ||_____  |  |   |    |__| |__| |__|" << endl;
	GoToXY(x, z + 5);	cout << "  |   |  |       ||       |  |       ||       | _____| |  |   |     __   __   __ " << endl;
	GoToXY(x, z + 6);	cout << "  |___|  |_______||_______|  |_______||_______||_______|  |___|    |__| |__| |__|" << endl;
	TextColor(240);
	x = x + 10;
	GoToXY(0, y + 12);
	for (int i = 0; i < 172; ++i)
		cout << DOWN_BLACK_PIECE;
	GoToXY(0, y + 24);
	for (int i = 0; i < 172; ++i)
		cout << DOWN_BLACK_PIECE;

	GoToXY(0, y + 17);
	for (int i = 0; i < 140; i++)
	{
		if ((i % 5) != 0) cout << UP_BLACK_PIECE;
		else cout << "  ";
	}
	GoToXY(0, y + 16);
	for (int i = 0; i < 140; i++)
	{
		if ((i % 5) != 0) cout << DOWN_BLACK_PIECE;
		else cout << "  ";
	}


	GoToXY(x - 10, z + 15);	cout << "         ^   ^        ";
	GoToXY(x - 10, z + 16);	cout << "         (o.o) /    ";
	GoToXY(x - 10, z + 17);	cout << "        /(   )/   ";
	GoToXY(x - 10, z + 18);	cout << "         | | |     ";
	GoToXY(x - 10, z + 19);	cout << "        (__)__)    ";
	for (int i = 0; i < 20; i++)
	{
		GoToXY(x + 20 - i, z + 13);	cout << "                  _..-------++._ " << endl;
		GoToXY(x + 20 - i, z + 14);	cout << "              _.-'/ |      _||  \\\"--._ " << endl;
		GoToXY(x + 20 - i, z + 15);	cout << "        __.--'`._/_\\j_____/_||___\\    `----. " << endl;
		GoToXY(x + 20 - i, z + 16);	cout << "   _.--'_____    |          \\     _____    / " << endl;
		GoToXY(x + 20 - i, z + 17);	cout << "  _j    /,---.\   |        =o |   /,---.\\   |_ " << endl;
		GoToXY(x + 20 - i, z + 18);	cout << "[__]==// .-. \\\\==`===========/==// .-. \\\\=[__] " << endl;
		GoToXY(x + 20 - i, z + 19);	cout << "  `-._|\\ `-' /|___\\_________/___|\\ `-' /|_.'    ";
		GoToXY(x + 20 - i, z + 20);	cout << "        `---'                     `---' ";
		Sleep(20);
	}
	GoToXY(x - 10, z + 15);	cout << "         ^   ^ ";
	GoToXY(x - 10, z + 16);	cout << "         (x.x) /";
	GoToXY(x - 10, z + 17);	cout << "        /(   )/";
	GoToXY(x - 10, z + 18);	cout << "         | | |";
	GoToXY(x - 10, z + 19);	cout << "        (__)__)";
}

void Game::winLogo() {
	TextColor(242);
	NoCursor();
	int x = 50;
	int y = 8;

	GoToXY(x + 34, y + 6);   cout << " __   __  _______  __   __    _     _  ___   __    _    __   __   __ " << endl;
	GoToXY(x + 34, y + 7);	 cout << "|  | |  ||       ||  | |  |  | | _ | ||   | |  |  | |  |  | |  | |  |" << endl;
	GoToXY(x + 34, y + 8);	 cout << "|  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| |  |  | |  | |  |" << endl;
	GoToXY(x + 34, y + 9);   cout << "|       ||  | |  ||  |_|  |  |       ||   | |       |  |  | |  | |  |" << endl;
	GoToXY(x + 34, y + 10);	 cout << "|_     _||  |_|  ||       |  |       ||   | |  _    |  |__| |__| |__|" << endl;
	GoToXY(x + 34, y + 11);	 cout << "  |   |  |       ||       |  |   _   ||   | | | |   |   __   __   __ " << endl;
	GoToXY(x + 34, y + 12);	 cout << "  |___|  |_______||_______|  |__| |__||___| |_|  |__|  |__| |__| |__|" << endl;
	TextColor(248);
	GoToXY(x - 20, y);       cout << R"(                 .__.--"""-,)" << endl;
	GoToXY(x - 20, y + 1);   cout << R"(               .'         `\)" << endl;
	GoToXY(x - 20, y + 2);   cout << R"(              /   _         \)" << endl;
	GoToXY(x - 20, y + 3);   cout << R"( .-""-.       |  (O\.--.-.-/O)          .-""-.)" << endl;
	GoToXY(x - 20, y + 4);   cout << R"(/ O O  \      .\|(_._.__._.__)         /  O O \)" << endl;
	GoToXY(x - 20, y + 5);   cout << R"(|O .-.  \    (   )   0 _ 0   \        /  .-. O|)" << endl;
	GoToXY(x - 20, y + 6);   cout << R"(\ (   )  '.   `-|     (_)     |     .'  (   ) /)" << endl;
	GoToXY(x - 20, y + 7);   cout << R"( '.`-'     '-./`|             |`\.-'     '-'.')" << endl;
	GoToXY(x - 20, y + 8);   cout << R"(   \         |  \   \     /   /  |         /)" << endl;
	GoToXY(x - 20, y + 9);   cout << R"(    \        \   '.  '._.'  .'   /        /)" << endl;
	GoToXY(x - 20, y + 10);  cout << R"(     \        '.   `'-----'`   .'        /)" << endl;
	GoToXY(x - 20, y + 11);  cout << R"(      \   .'    '-._        .-'\   '.   /)" << endl;
	GoToXY(x - 20, y + 12);  cout << R"(       |/`          `'''''')    )    `\|)" << endl;

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

void Game::loadingBar() {
	TextColor(240);
	NoCursor();

	int x = 61;
	int y = 18;
	for (int i = 18; i < 28; ++i) {
		GoToXY(40, i);
		for (int j = 0; j < 100; ++j) {
			cout << " ";
		}
	}

	y = 20;
	GoToXY(80, y - 1);	cout << "LOADING...";
	GoToXY(x - 1, y);
	for (int i = 0; i < 70; ++i)
		cout << DOWN_BLACK_PIECE;

	GoToXY(x - 1, y + 2);
	for (int i = 0; i < 70; ++i)
		cout << UP_BLACK_PIECE;

	GoToXY(x - 1, y + 1);
	cout << VERTICAL_BLACK_PIECE;
	GoToXY(x + 68, y + 1);
	cout << VERTICAL_BLACK_PIECE;

	GoToXY(x, y + 1);
	for (int i = 0; i < 68; ++i) {
		Sleep(20);
		cout << char(178);
	}

	while (_kbhit())
		_getch();
}

void Game::settings() {
	NoCursor();
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
					PlaySound(TEXT("Sound\\Theme.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				}
				else {
					TextColor(240);
					GoToXY(x + 13, y + 3); cout << "OFF";
					PlaySound(NULL, NULL, SND_ASYNC);
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
		CRLogo();
		if (checkMute == false)
			PlaySound(TEXT("Sound\\Theme.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		NoCursor();
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
		checkLoadGame = false;
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
					//loadingBar();
					TextColor(240);
					newGame();
					break;
				}
			}
			if (cnt == 2) {
				TextColor(15);
				GoToXY(x + 5, y + 3); cout << " LOAD  GAME ";
				if (choice == KEY_ENTER) {
					loadGame();

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
		while (true) {
			if (checkLoadGame == true) {
				clrscr();
				//CRLogo();
				loadingBar();
				TextColor(240);
				newGame();
			}
			else
				break;
		}
	}
}

void Game::newGame() {
	NoCursor();
	TextColor(240);

	if (checkLoadGame == false) {
		map.~Map();
		new(&map) Map();
		new(&map.level) Level(mode, 1);
	}

	clrscr();
	map.printMap();
	map.drawPlayer();

	if (checkLoadGame == false)
		map.initializeMap();

	map.initialRender();

	checkLoadGame = false;
	checkPauseGame = false;
	int frameTime = 0;
	int round = map.level.getLevel();
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
			map.generateMap(frameTime);
		}
		else if (checkPauseGame == true) {
			TextColor(246); GoToXY(133, 23); cout << MIDDLE_SMALL_BLACK_PIECE << " PAUSE GAME " << endl;
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
						TextColor(240);
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
						TextColor(240);
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
				saveGame();
				clrscr();
				map.printMap();
				map.initialRender();
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
				loadGame();

				checkPauseGame = false;
				if (checkLoadGame == true)
					return;
				else {
					clrscr();
					map.printMap();
					map.initialRender();
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

		if (map.checkCollision()) {
			Sleep(1500);
			checkPauseGame = false;
			TextColor(240);
			clrscr();
			PlaySound(TEXT("Sound\\GameOver.wav"), NULL, SND_FILENAME | SND_ASYNC);
			for (int i = 0; i < 5; ++i) {
				clrscr();
				TextColor(i);
				loseLogo();
				Sleep(140);
			}
			while (_kbhit())
				_getch();
			GoToXY(77, 10);		cout << "*** Press any key to continue ***";
			TextColor(240);
			_getch();
			return;
		}

		if (map.checkWin() == true) {
			if (map.checkMaxLevel() == true) {
				clrscr();
				PlaySound(TEXT("Sound\\Victory.wav"), NULL, SND_FILENAME | SND_ASYNC);
				for (int i = 0; i < 16; ++i) {
					clrscr();
					TextColor(i);
					winLogo();
					Sleep(140);
				}
				while (_kbhit())
					_getch();
				GoToXY(94, 22);		cout << "*** Press any key to continue ***";
				TextColor(240);
				_getch();
				return;
			}

			round++;
			PlaySound(TEXT("Sound\\LevelUp.wav"), NULL, SND_FILENAME | SND_ASYNC);
			TextColor(250);
			GoToXY(57, 2); cout << "LEVEL UP!!!";
			Sleep(1500);
			
			GoToXY(57, 2); cout << "            ";
			GoToXY(142, 8); cout << round;
			TextColor(240);
			map.fillInsideMap();
			map.levelUp();
			map.resetPlayer();
			map.initializeMap();
			map.printMap();
			map.initialRender();
			map.drawPlayer();
			if (checkMute == false)
				PlaySound(TEXT("Sound\\Theme.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			while (_kbhit())
				_getch();
		}

	}
}
vector<string> showListFiles() {
	TextColor(240);
	ifstream filein1("Data\\empty.txt");
	if (!filein1) {
		cout << "\nERROR";
	}

	string n1;

	vector<string>a;
	while (!filein1.eof()) {
		getline(filein1, n1);
		a.push_back(n1);
	}
	filein1.close();
	ifstream filein("Data\\listFiles.txt");
	if (!filein) {
		cout << "\nERROR";
	}

	string n;


	int i = 0;
	while (getline(filein, n)) {

		a.erase(a.begin() + a.size() - 1);
		a.insert(a.begin() + 0, n);
	}

	filein.close();
	int temp = 0;

	int x = 84;
	int y = 21;
	for (int i = 1; i < a.size() * 2 + 1; i += 2) {
		GoToXY(x - 22, y + i);
		cout << a[temp++];
	}
	return a;
}

void Game::loadGame() {
	logoLoadGame();
	int x = 61;
	int y = 18;
	GoToXY(x + 1, y + 1);
	cout << "Choose your file (Press ESC to return): ";
	vector<string> list = showListFiles();


	for (int i = 0; i < list.size() * 3; i++) {
		GoToXY(x - 1, y + (i + 1));
		cout << VERTICAL_PALE_PIECE;
		GoToXY(x + 68, y + (i + 1));
		cout << VERTICAL_PALE_PIECE;
	}
	GoToXY(x, y);
	for (int i = 0; i < 68; ++i)
		cout << HORIZONTAL_PALE_PIECE;

	GoToXY(x, y + list.size() * 3);
	for (int i = 0; i < 68; ++i)
		cout << HORIZONTAL_PALE_PIECE;

	GoToXY(x - 1, y);
	cout << UP_LEFT_CORNER_PALE_PIECE;
	GoToXY(x - 1, y + list.size() * 3);
	cout << DOWN_LEFT_CORNER_PALE_PIECE;

	GoToXY(x + 68, y);
	cout << UP_RIGHT_CORNER_PALE_PIECE;
	GoToXY(x + 68, y + list.size() * 3);
	cout << DOWN_RIGHT_CORNER_PALE_PIECE;
	string file;
	int temp2 = 0;
	int temp = 0;
	while (true) {
		char choice = _getch();
		TextColor(240);

		int x2 = 84;
		int y2 = 21;
		for (int i = 1; i < list.size() * 2 + 1; i += 2) {
			GoToXY(x2 - 22, y2 + i);
			cout << list[temp2++];
		}
		temp2 = 0;

		if (choice == KEY_DOWN || choice == 'S' || choice == 's') {
			temp++;

			if (temp > list.size()) {
				temp = 1;
				//tempx = temp * 2 + 1;
			}
		}
		if (choice == KEY_UP || choice == 'W' || choice == 'w') {
			temp--;

			if (temp < 1) {
				temp = list.size();
				//tempx = temp * 2 + 1;
			}
		}
		if (choice == 27) {
			return;
		}

		if (temp == 1) {
			TextColor(15);
			if (temp > list.size()) continue;
			GoToXY(x2 - 22, y2 + temp * 2 - 1);
			cout << list[temp - 1];
			if (choice == KEY_ENTER) {
				file = list[temp - 1];
				break;
			}
		}
		if (temp == 2) {
			TextColor(15);
			if (temp > list.size()) continue;
			GoToXY(x2 - 22, y2 + temp * 2 - 1);
			cout << list[temp - 1];


			if (choice == KEY_ENTER) {
				file = list[temp - 1];
				break;
			}
		}
		if (temp == 3) {
			TextColor(15);
			if (temp > list.size()) continue;
			GoToXY(x2 - 22, y2 + temp * 2 - 1);
			cout << list[temp - 1];


			if (choice == KEY_ENTER) {
				file = list[temp - 1];
				break;

			}
		}
		if (temp == 4) {
			TextColor(15);
			if (temp > list.size()) continue;
			GoToXY(x2 - 22, y2 + temp * 2 - 1);
			cout << list[temp - 1];

			if (choice == KEY_ENTER) {
				file = list[temp - 1];
				break;
			}
		}

		if (temp == 5) {
			TextColor(15);
			if (temp > list.size()) continue;
			GoToXY(x2 - 22, y2 + temp * 2 - 1);
			cout << list[temp - 1];


			if (choice == KEY_ENTER) {
				file = list[temp - 1];
				break;
			}
		}
		if (temp == 6) {
			TextColor(15);
			if (temp > list.size()) continue;
			GoToXY(x2 - 22, y2 + temp * 2 - 1);
			cout << list[temp - 1];

			if (choice == KEY_ENTER) {
				file = list[temp - 1];
				break;

			}
		}
		if (temp == 7) {
			TextColor(15);
			if (temp > list.size()) continue;
			GoToXY(x2 - 22, y2 + temp * 2 - 1);
			cout << list[temp - 1];

			if (choice == KEY_ENTER) {
				file = list[temp - 1];
				break;

			}
		}
		if (temp == 8) {
			TextColor(15);
			if (temp > list.size()) continue;
			GoToXY(x2 - 22, y2 + temp * 2 - 1);
			cout << list[temp - 1];


			if (choice == KEY_ENTER) {
				file = list[temp - 1];
				break;

			}
		}
		if (temp == 9) {
			TextColor(15);
			if (temp > list.size()) continue;
			GoToXY(x2 - 22, y2 + temp * 2 - 1);
			cout << list[temp - 1];



			if (choice == KEY_ENTER) {
				file = list[temp - 1];
				break;
				}
		}
		if (temp == 10) {
			TextColor(15);
			if (temp > list.size()) continue;
			GoToXY(x2 - 22, y2 + temp * 2 - 1);
			cout << list[temp - 1];
		}


		if (choice == KEY_ENTER) {
			file = list[temp - 1];
			break;
		}
	}
	//Sleep(10000);

	string filename = "Data/";
	filename += file + ".bin";


	if (map.loadGame(filename, mode) == false) {
		checkLoadGame = false;
		GoToXY(x + 20, y + 3);
		cout << "Error! Please try again later!";

		NoCursor();
		Sleep(800);
		while (_kbhit())
			_getch();
		return;
	}
	else {
		checkLoadGame = true;
	}

	NoCursor();
	Sleep(50);
	while (_kbhit())
		_getch();
}

void Game::saveGame() {
	logoSaveGame();
	int x = 61;
	int y = 18;

	GoToXY(x, y);
	for (int i = 0; i < 68; ++i)
		cout << HORIZONTAL_PALE_PIECE;

	GoToXY(x, y + 2);
	for (int i = 0; i < 68; ++i)
		cout << HORIZONTAL_PALE_PIECE;

	GoToXY(x - 1, y);
	cout << UP_LEFT_CORNER_PALE_PIECE;
	GoToXY(x - 1, y + 2);
	cout << DOWN_LEFT_CORNER_PALE_PIECE;

	GoToXY(x + 68, y);
	cout << UP_RIGHT_CORNER_PALE_PIECE;
	GoToXY(x + 68, y + 2);
	cout << DOWN_RIGHT_CORNER_PALE_PIECE;

	GoToXY(x - 1, y + 1);
	cout << VERTICAL_PALE_PIECE;
	GoToXY(x + 68, y + 1);
	cout << VERTICAL_PALE_PIECE;

	GoToXY(x + 1, y + 1);


	cout << "Enter your file here: ";
	
	
	Cursor();
	string file;
	cin >> file;

	NoCursor();
	Sleep(50);

	while (_kbhit())
		_getch();

	map.saveGame(file, mode);
	GoToXY(x + 22, y + 3);
	cout << "Save File Successfully!";

	NoCursor();
	Sleep(800);
	while (_kbhit())
		_getch();

}

void checkReturn()
{
	int key = 0;
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();

			if (key == 27)
				break;
		}
	}
}