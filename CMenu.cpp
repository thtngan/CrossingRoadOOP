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

	if (ConstantVar::_typePlayer == 0) {
		currentChoice[1] = "(O.O)";
	}
	else if (ConstantVar::_typePlayer == 1) {
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
					isMusic = !isMusic;
					if (isMusic) {
						currentChoice[0] = "ON ";
					}
					else {
						currentChoice[0] = "OFF";
					}
					input = true;
					break;
				case 1: //Player
					ConstantVar::_typePlayer = (ConstantVar::_typePlayer + 1) % 3;
					if (ConstantVar::_typePlayer == 0) {
						currentChoice[1] = "(O.O)";
					}
					else if (ConstantVar::_typePlayer == 1) {
						currentChoice[1] = "(^O^)";
					}
					else {
						currentChoice[1] = "(>_<)";
					}
					input = true;
					break;
				case 2: //FAQs
					printFAQs();
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


void CMenu::printFAQs() {
	int color = rand() % 15 + 1;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	gotoXY(30, 13); cout << "WHAT IS THIS?                 " << endl;
	gotoXY(30, 14); cout << "Crossing Road is a little game with a simple concept:" << endl;
	gotoXY(30, 15); cout << "help your character cross a road." << endl;
	gotoXY(30, 17); cout << "HOW TO PLAY?                 " << endl;
	gotoXY(30, 18); cout << "Use 'WS' to move your character from side to side" << endl;
	gotoXY(30, 19); cout << "while 'AD' to move left and right." << endl;
	gotoXY(45, 22); cout << ".... Press any key to hide FAQs ...." << endl;

	if (getch()) {
		ClearScreen();
		return;
	}

}


//Exit
void CMenu::printGB() {
	int color = rand() % 15 + 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	
	CTrain train;

	gotoXY(40, 10);
	for (int i = 40; i >= 0; i--)
	{
		Sleep(35);
		gotoXY(40 + i, 10);
		for (int j = 0; j < train.getW(); j++)
			cout << train.kind()[0][j];

		gotoXY(40 + i, 11);
		for (int j = 0; j < train.getW(); j++)
			cout << train.kind()[1][j];
		
		gotoXY(40 + i, 12);
		for (int j = 0; j < train.getW(); j++)
			cout << train.kind()[2][j];

		gotoXY(40 + i, 13);
		for (int j = 0; j < train.getW(); j++)
			cout << train.kind()[3][j];
	}

}