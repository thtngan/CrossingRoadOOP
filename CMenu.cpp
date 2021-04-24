#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "CMenu.h"

void CMenu::printTitle() {
	int color = rand() % 15 + 1;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	
	gotoXY(10, 3); cout << " ______  ______   ______   ______   ______  _____  ______   ______     ______   ______   ______   _____   ";
	gotoXY(10, 4); cout << "| |     | |  | \\ / |  | \\ / |      / |       | |  | |  \\ \\ | | ____   | |  | \\ / |  | \\ | |  | | | | \\ \\  ";
	gotoXY(10, 5); cout << "| |     | |__| | | |  | | '------. '------.  | |  | |  | | | |  | |   | |__| | | |  | | | |__| | | |  | | ";
	gotoXY(10, 6); cout << "|_|____ |_|  \\_\\ \\_|__|_/  ____|_/  ____|_/ _|_|_ |_|  |_| |_|__|_|   |_|  \\_\\ \\_|__|_/ |_|  |_| |_|_/_/  ";
	gotoXY(10, 7); cout << "                                                                                                          ";

}

void CMenu::menu() {
	system("cls");

	const string choice[5] = { "New Game", "Load Game", "Rank", "Settings", "Exit" };
	bool input = true;
	int x = 35, y = 10, pos = 0;
	
	ShowConsoleCursor(false);

	while (true) {
		input = true;
		while (true) {
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

				printTitle();

				input = false;

			}
			input = false;
			switch (getch()) {
				input = true;
			case 72:
				input = true;
				pos--;
				pos = (pos + 5) % 5;
				break;
			case 80:
				input = true;
				pos++;
				pos %= 5;
				break;
			case 13:
				switch (pos) {
				case 0: //New game
					while (1) {
						loading();
						Sleep(2000);
						map.printBorders();
						CObject* a = new CTrain();
						line.PushObj(a);
						map.printMap();
					}
					break;
				case 1: //Loadgame
					cout << "Loadgame";
					break;
				case 2: //Rank
					//Rank
					cout << "Rank";

					input = true;
					break;
				case 3: //Settings
					Sleep(1000);
					settings();
					break;
				case 4: //Exit
					system("cls");
					return;
				}
				break;
			}
		}

	}
}



void CMenu::settings() {
	ClearScreen();
	printTitle();

	
}

void CMenu::loading() {
	ClearScreen();
	printTitle();
	


}