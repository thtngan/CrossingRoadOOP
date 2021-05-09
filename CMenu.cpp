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
	int cur;
	while (true) {
		if (ConstantVar::_isMusic) {
			PlaySoundW(L"M_Intro.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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
						if (newGame(1)) {
							Sleep(500);
							system("cls");
							input = true;
							break;
						}
					}
					if (ConstantVar::_isMusic) {
						PlaySoundW(L"M_Intro.wav", NULL, SND_FILENAME | SND_ASYNC);
					}
					break;
				case 1: //Loadgame
					cur = loadGame();
					if (cur == 0) {
						Sleep(500);
						system("cls");
						input = true;
					}
					else
						if (newGame(cur)) {
							Sleep(500);
								system("cls");
								input = true;
								break;
						}
					if (ConstantVar::_isMusic) {
						PlaySoundW(L"M_Intro.wav", NULL, SND_FILENAME | SND_ASYNC);
					}
					break;
				case 2: //Rank
					//Rank
					leaderBoard();
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
	if (ConstantVar::_isMusic) {
		PlaySoundW(L"M_Loading.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
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
bool CMenu::newGame(const int& t) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	map.~CMap();
	new(&map) CMap();
	map.loadLevel(t);
	map.printBorders();
	map.printInstruct();
	map.init();
	Sleep(500);
	bool non_stop = true;
	char m;
	bool flag = true, flagMenu = true;
	if (ConstantVar::_isMusic) {
		PlaySoundW(L"M_PlayGame.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	while (non_stop)
	{
		if (flag)
		{
			map.random();
			if (_kbhit())
			{
				m = _getch();
				fflush(stdin);
				switch (m)
				{
				case 'a': case 'A':
					map.movePlayer(m);
					break;
				case 'w': case 'W':
					map.movePlayer(m);
					break;
				case 's': case 'S':
					map.movePlayer(m);
					break;
				case 'd': case 'D':
					map.movePlayer(m);
					break;
				case 'p': case 'P':
					flag = false;
					gotoXY(50, 30);
					cout << "PAUSED - Press double p to continue";
					while (flagMenu) {
						int status = pauseMenu();
						if (status == 0)
							return true;
						else if (status == 1) {
							gotoXY(138, 25); cout << "Saved...";
						}
						else
							flagMenu = false;
					}
				}
			}
		}
		else
		{
			if (_kbhit())
			{	
				
				m = _getch();
				switch (m)
				{
				case 'p': case 'P':
					flag = true;
					flagMenu = true;
					clsPauseMenu();
					break;
				}
			}
		}
		if (map.collision())
		{
			return true;
		}
		if (map.isWin()) {
			if (map.printLevelUp()) {
				map.nextLevel();
				map.printInstruct();
				map.deletePlayer();
				map.init();
				map.printPlayer();
			}
			else
				return true;
		}
	}
	return false;
}
//LoadGame
vector<int> CMenu::readFile(const string& name) {
	ifstream ifs;
	ifs.open(name.c_str());
	vector<int> list;
	if (!ifs.is_open())
		return list;	
	int temp;
	while (!ifs.eof()) {
		ifs >> temp;
		list.push_back(temp);
	}
	ifs.close();
	return list;
}
void CMenu::writeFile(const string& name, vector<int> list) {
	ofstream ofs;
	ofs.open(name.c_str());
	if (!ofs.is_open())
		return;
	for(int i = 0; i < list.size() - 1; ++i)
		ofs << list[i] << " ";
	ofs << list[list.size() - 1];
	ofs.close();
}
int CMenu::loadGame() {
	ClearScreen();
	string name = "test.txt";
	vector<int> list = readFile(name);
	if (list.empty()) {
		gotoXY(30, 15);
		cout << "Nothing to load";
		Sleep(1000);
		return false;
	}
	gotoXY(10, 2);	cout << " .----------------.  .----------------.  .----------------.  .----------------.   .----------------.  .----------------.  .----------------.  .----------------. ";
	gotoXY(10, 3);	cout << "| .--------------. || .--------------. || .--------------. || .--------------. | | .--------------. || .--------------. || .--------------. || .--------------. |";
	gotoXY(10, 4);	cout << "| |   _____      | || |     ____     | || |      __      | || |  ________    | | | |    ______    | || |      __      | || | ____    ____ | || |  _________   | |";
	gotoXY(10, 5);	cout << "| |  |_   _|     | || |   .'    `.   | || |     /  \\     | || | |_   ___ `.  | | | |  .' ___  |   | || |     /  \\     | || ||_   \\  /   _|| || | |_   ___  |  | |";
	gotoXY(10, 6);	cout << "| |    | |       | || |  /  .--.  \\  | || |    / /\\ \\    | || |   | |   `. \\ | | | | / .'   \\_|   | || |    / /\\ \\    | || |  |   \\/   |  | || |   | |_  \\_|  | |";
	gotoXY(10, 7);	cout << "| |    | |   _   | || |  | |    | |  | || |   / ____ \\   | || |   | |    | | | | | | | |    ____  | || |   / ____ \\   | || |  | |\\  /| |  | || |   |  _|  _   | |";
	gotoXY(10, 8);	cout << "| |   _| |__/ |  | || |  \\  `--'  /  | || | _/ /    \\ \\_ | || |  _| |___.' / | | | | \\ `.___]  _| | || | _/ /    \\ \\_ | || | _| |_\\/_| |_ | || |  _| |___/ |  | |";
	gotoXY(10, 9);	cout << "| |  |________|  | || |   `.____.'   | || ||____|  |____|| || | |________.'  | | | |  `._____.'   | || ||____|  |____|| || ||_____||_____|| || | |_________|  | |";
	gotoXY(10, 10); cout << "| |              | || |              | || |              | || |              | | | |              | || |              | || |              | || |              | |";
	gotoXY(10, 11); cout << "| '--------------' || '--------------' || '--------------' || '--------------' | | '--------------' || '--------------' || '--------------' || '--------------' |";
	gotoXY(10, 12); cout << " '----------------'  '----------------'  '----------------'  '----------------'   '----------------'  '----------------'  '----------------'  '----------------' ";
	int cur = 0;
	for (int i = 0; i < (int)list.size(); ++i) {
		if (i == cur) {
			gotoXY(33, 16 + i);
			cout << (char)16;
		}
		gotoXY(35, 16 + i);
		cout << "Level " << list[i] << endl;
	}

	gotoXY(35, 16 + list.size() + 3);	cout << "Press ESC to escape ...";
	while (true) {
		if (kbhit())
		{
			char key = getch();
			if (key == 'w' || key == 'W')
			{
				gotoXY(33, 16 + cur);
				cout << "  Level " << list[cur];
				cur--;
				cur = (cur + list.size()) % list.size();
				gotoXY(33, 16 + cur);
				cout << (char)16 << " Level " << list[cur];
			}
			if (key == 's' || key == 'S')
			{
				gotoXY(33, 16 + cur);
				cout << "  Level " << list[cur];
				cur++;
				cur = (cur + list.size()) % list.size();
				gotoXY(33, 16 + cur);
				cout << (char)16 << " Level " << list[cur];
			}
			if (key == 13)
			{
				int t = list[cur];
				list.erase(list.begin() + cur);
				writeFile(name, list);
				ClearScreen();
				return t;
			}
			if (key == 27)
			{
				ClearScreen();
				return 0;
			}
		}
		Sleep(200);
	}
}
//Settings
void CMenu::settings() {
	ClearScreen();

	const char *choice[4] = { "Music:", "Player:", "FAQs", "Back"};
	string currentChoice[4] = { "ON", "(0.0)", "", "" };

	if (ConstantVar::_isMusic) {
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
					ConstantVar::_isMusic = !ConstantVar::_isMusic;
					if (ConstantVar::_isMusic) {
						currentChoice[0] = "ON ";
						PlaySoundW(L"M_Select.wav", NULL, SND_FILENAME | SND_ASYNC);
						PlaySoundW(L"M_Intro.wav", NULL, SND_FILENAME | SND_ASYNC);
					}
					else {
						currentChoice[0] = "OFF";
						PlaySoundW(L"M_Select.wav", NULL, SND_FILENAME | SND_ASYNC);
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

void CMenu::leaderBoard()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoXY(50, 1); cout << "(                                                                     ";
	gotoXY(50, 2); cout << ")/ )                 (                    )                       (    ";
	gotoXY(50, 3); cout << "(()/(     (      )    )/ )    (   (     ( /(            )   (      )/ )";
	gotoXY(50, 4); cout << " /(_))   ))/  ( /(   (()/(   ))/  )(    )/())   (    ( /(   )(    (()/(";
	gotoXY(50, 5); cout << "(_))    /((_ ))(_))   ((_) )/((_)(()/  ((_)/    )/   )(_)) (()/    ((_))";
	gotoXY(50, 6); cout << "| |    (_))  ((_)_    _| | (_))   ((_) | |(_)  ((_) ((_)_   ((_)   _| |";
	gotoXY(50, 7); cout << "| |__  / -_) / _` | / _` | / -_) | '_| | '_ | / _ | / _` | | '_| / _` |";
	gotoXY(50, 8); cout << "|____| |___| |__,_| |__,_| |___| |_|   |_.__/ |___/ |__,_| |_|   |__,_|";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	int x = 80, y = 12;
	string line;
	ifstream f("rank.txt");
	if (!f.is_open())
	{
		gotoXY(x, y); cout << "Unable to open file";
	}
	else 
	{
		while (!f.eof())
		{
			getline(f, line);
			gotoXY(x, y);
			cout << line << '\n';
			y = y + 2;
		}
	}
	f.close();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoXY(73, 30); cout << "PRESS--ANY--KEY--TO--GO--BACK";
	while (true)
	{
		if (_kbhit())
		{
			if (getch()) 
			{ 
				system("cls");
				return; 
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

	if (ConstantVar::_isMusic) {
		PlaySoundW(L"M_Goodbye.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	
	CTrain train;

	gotoXY(40, 10);
	for (int i = 40; i >= 0; i--)
	{
		Sleep(50);
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
//Pause Menu
void CMenu::saveGame(const int& t) {
	ofstream ofs;
	ofs.open("test.txt", ios::app);
	ofs << " " << t;
	ofs.close();
}
int CMenu::pauseMenu() {
	const string choice[2] = { "Save Game", "Quit" };
	gotoXY(138, 20); cout << "PAUSE MENU" << endl;
	int x = 138, y = 21, pos = 0;
	//Print list of menu
	while (true) {
		for (int i = 0; i < 2; i++) {
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
		switch (getch()) {
		case 'w': case 'W':
			pos--;
			pos = (pos + 2) % 2;
			break;
		case 's': case 'S':
			pos++;
			pos = (pos + 2) % 2;
			break;
		case 13:
			if (pos == 0) { // Save Game
				saveGame(map.getLevel());
				return 1;
			}
			else { // Quit
				return 0;
			}
			break;
		case 'p' : case 'P':
			return -1;
		}
	}
}
void CMenu::clsPauseMenu() {
	gotoXY(50, 30);  cout << "                                   ";
	gotoXY(138, 20); cout << "                      ";
	gotoXY(138, 21); cout << "                      ";
	gotoXY(138, 22); cout << "                      ";
	gotoXY(138, 25); cout << "                      ";
}