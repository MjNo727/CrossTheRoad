#include "GAME.h"

void GoToXY(int x, int y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}


void TxtColor(int color) {
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
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
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

void Game::fillMenu() {
	TxtColor(15);
	for (int i = 18; i < 28; ++i) {
		GoToXY(74, i);
		for (int j = 0; j < 22; ++j) {
			cout << " ";
		}
	}
}

void Game::xxx(int x, int y )
{
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
}
void Game::menu() {
	while (true) {
		clrscr();
		
		NoCursorType();
		TxtColor(15);
		int x = 74;
		int y = 18;
		
		xxx(x,y);
		TxtColor(15);
		GoToXY(x + 7, y + 1); cout << "NEW GAME";
		GoToXY(x + 5, y + 3); cout << "LOADING GAME";
		GoToXY(x + 7, y + 5); cout << "SETTINGS";
		GoToXY(x + 9, y + 7); cout << "EXIT";

		int cnt = 0;
		//checkLoadGame = false;
		while (true) {
			char choice = _getch();
			TxtColor(15);
			GoToXY(x + 6, y + 1); cout << " NEW GAME ";
			GoToXY(x + 4, y + 3); cout << " LOADING GAME ";
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
				TxtColor(240);
				GoToXY(x + 6, y + 1); cout << " NEW GAME ";
				if (choice == KEY_ENTER) {
					//newGame();

					NoCursorType();
					TxtColor(15);
					fillMenu();
					xxx(x, y);
					GoToXY(x + 6, y + 1); cout << " RETURN ";
					while (true)
					{
						
						char choice = _getch();
						TxtColor(240);
						GoToXY(x + 6, y + 1); cout << "RETURN ";
						
						if (choice == KEY_ENTER) {
							fillMenu();
							xxx(x, y);
							GoToXY(x + 7, y + 1); cout << "NEW GAME";
							TxtColor(240);
							GoToXY(x + 5, y + 3); cout << "LOADING GAME";
							TxtColor(15);
							GoToXY(x + 6, y + 5); cout << " SETTINGS ";
							GoToXY(x + 9, y + 7); cout << "EXIT";
							break;

						}
					}
					
					//break;
				}
			}
			if (cnt == 2) {
				TxtColor(240);
				GoToXY(x + 4, y + 3); cout << " LOADING GAME ";
				if (choice == KEY_ENTER) {

					//loadGame();
					TxtColor(15);
					fillMenu();
					xxx(x, y);
					GoToXY(x + 6, y + 1); cout << " Exit ";
					while (true)
					{

						char choice2 = _getch();
						TxtColor(240);
						GoToXY(x + 6, y + 1); cout << "Exit ";

						if (choice2 == KEY_ENTER) {
							fillMenu();
							xxx(x, y);
							GoToXY(x + 7, y + 1); cout << "NEW GAME";
							TxtColor(240);
							GoToXY(x + 5, y + 3); cout << "LOADING GAME";
							TxtColor(15);
							GoToXY(x + 6, y + 5); cout << " SETTINGS ";
							GoToXY(x + 9, y + 7); cout << "EXIT";
							break;
						}
					}
					//break;
				}
			}
			if (cnt == 3) {
				TxtColor(240);
				GoToXY(x + 6, y + 5); cout << " SETTINGS ";
				if (choice == KEY_ENTER) {
					//settings();
					TxtColor(15);
					fillMenu();
					xxx(x, y);
					GoToXY(x + 6, y + 1); cout << " Exit ";
					while (true)
					{
						char choice2 = _getch();
						TxtColor(240);
						GoToXY(x + 6, y + 1); cout << "Exit ";

						if (choice2 == KEY_ENTER) {
							fillMenu();
							xxx(x, y);
							TxtColor(240);
							GoToXY(x + 7, y + 1); cout << "NEW GAME";
							TxtColor(15);
							GoToXY(x + 5, y + 3); cout << "LOADING GAME";
							GoToXY(x + 6, y + 5); cout << " SETTINGS ";
							GoToXY(x + 9, y + 7); cout << "EXIT";
							break;
							
						}
					}
				}
			}
			if (cnt == 4) {
				TxtColor(240);
				GoToXY(x + 8, y + 7); cout << " EXIT ";
				if (choice == KEY_ENTER) {
					TxtColor(15);
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
		//		TxtColor(15);
		//		newGame();
		//	}
		//	else
		//		break;
		//}
	}
}