#include "CMenu.h"

void CMenu::menu() {
	system("cls");

	const string choice[5] = { "New Game", "Load Game", "Rank", "Settings", "Exit" };

	int color = rand() % 16 + 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	gotoXY(10, 3); cout << " ______  ______   ______   ______   ______  _____  ______   ______     ______   ______   ______   _____   ";
	gotoXY(10, 4); cout << "| |     | |  | \\ / |  | \\ / |      / |       | |  | |  \\ \\ | | ____   | |  | \\ / |  | \\ | |  | | | | \\ \\  ";
	gotoXY(10, 5); cout << "| |     | |__| | | |  | | '------. '------.  | |  | |  | | | |  | |   | |__| | | |  | | | |__| | | |  | | ";
	gotoXY(10, 6); cout << "|_|____ |_|  \\_\\ \\_|__|_/  ____|_/  ____|_/ _|_|_ |_|  |_| |_|__|_|   |_|  \\_\\ \\_|__|_/ |_|  |_| |_|_/_/  ";
	gotoXY(10, 7); cout << "                                                                                                          ";

	bool input = true;
	int x = 35, y = 10, pos = 0;
	if (input) {
		//Print list of menu
		for (int i = 0; i < 5; i++) {
			gotoXY(x, y + i);
			if (i == pos)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << choice[i] << endl;
		}
	}
	input = false;

	switch (inputB()) {
		input = true;
		
	case 'w' : case 'W':
		input = true;
		pos--;
		pos = (pos + 5) % 5;
		break;

	case 's' : case 'S':
		input = true;
		pos++;
		pos = (pos + 5) % 5;
		break;
	}
}
