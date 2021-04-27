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
	int x = 50, y = 10, pos = 0;
	
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
			}
			input = false;
			switch (getch()) {
				input = true;
			case 'w': case 'W':
				input = true;
				pos--;
				pos = (pos + 5) % 5;
				break;
			case 's': case 'S':
				input = true;
				pos++;
				pos %= 5;
				break;
			case 13:
				switch (pos) {
				case 0: //New game
					while (1) {
						loading(); 
						map.printBorders();
						CObject* a = new CTrain();
						line.PushObj(a);
						map.printMap();
						map.move();
						//map.init();
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
					Sleep(500);
					settings();
					input = true;
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

//New game
void CMenu::loading() {
	ClearScreen();
	printTitle();

	gotoXY(40, 20);
	cout << "[";
	for (int i = 0; i <= 50; i++)
	{
		Sleep(35);
		gotoXY(40 + i, 20);
		printf("%c", 219);
		gotoXY(40 + i, 21);
		printf("%c", 219);
		gotoXY(40 + 25, 22);
		cout << i * 2 << "%";
	}

}



//Settings
void CMenu::settings() {
	ClearScreen();

	const char *choice[4] = { "Music:", "Player:", "FAQs", "Back"};
	string currentChoice[4] = { "ON", "(0.0)", "", "" };

	if (isMusic) {
		currentChoice[0] = "ON";
	}
	else {
		currentChoice[1] = "OFF";
	}

	if (typePlayer == 0) {
		currentChoice[1] = "(O.O)";
	}
	else if (typePlayer == 1) {
		currentChoice[1] = "(^O^)";
	}
	else {
		currentChoice[1] = "(>O<)";
	}
	bool input = true;
	int x = 50, y = 10, pos = 0;

	while (true) {
		if (input) {
			//Print list of choice
			for (int i = 0; i < 4; i++) {
				gotoXY(x, y + i);
				if (i == pos)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				cout << choice[i] << currentChoice[i] << endl;
			}

			printTitle();

			input = false;

			switch (getch()) {
				input = true;
			case 'w': case 'W':
				input = true;
				pos--;
				pos = (pos + 4) % 4;
				break;
			case 's': case 'S':
				input = true;
				pos++;
				pos %= 4;
				break;
			case 13:
				switch (pos) {
				case 0: //Music
					
					break;
				case 1: //Player
					cout << "Loadgame";
					break;
				case 2: //FAQs
					//Rank
					cout << "Rank";

					input = true;
					break;

				case 3: //Back
					system("cls");
					return;
				}
				break;
			}

		}
	}

	
	
}

