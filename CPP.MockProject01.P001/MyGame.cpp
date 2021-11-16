#include <Windows.h>

#include "MyGame.h"
#include "ChessTable.h"
#include "MyConsole.h"

MyGame::MyGame() {
	replayGames = new Matrix * [NUMBER_OF_GAME_REPLAY];
	for (int i = 0; i < NUMBER_OF_GAME_REPLAY; i++) {
		replayGames[i] = new Matrix();
	}
}

void MyGame::Menu(WORD color) {
	DeleteArea(35, 75, 0, 0);
	GotoXY(0, 0);

	SetColor(color);

	int c;

	do {
		cout << "*--------------MAIN MENU------------*" << endl;
		cout << "1.Play with other player" << endl;
		cout << "2.Play with BOT" << endl;
		cout << "3.Replay" << endl;
		cout << "4.Player's Infomation" << endl;
		cout << "5.Guild" << endl;
		cout << "6.Exit" << endl;
		cout << "Press number to choose: "; cin >> c;

		switch (c) {
		case 1:
			playWithPlayer();
			break;
		case 2:
			menuPlayWithBOT(color);
			break;
		case 3:
			replay();
			break;
		case 4:
			break;
		case 5:
			Guild();
			break;
		case 6:
			break;
		}
	} while (c != 6);
}

void Guild(WORD color) {
	SetColor(color);
	cout << "*--------------HOW TO PLAY------------*" << endl;
}

void MyGame::menuPlayWithBOT(WORD color) {
	DeleteArea(8, 50, 0, 0);
	GotoXY(0, 0);

	SetColor(color);

	int c;

	do {
		cout << "*--------------PLAY WITH BOT------------*" << endl;
		cout << "1.Easy Mode" << endl;
		cout << "2.Normal Mode" << endl;
		cout << "3.Hard Mode" << endl;
		cout << "4.Back to MAIN MENU" << endl;
		cout << "Press number to choose: "; cin >> c;

		switch (c) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			Menu(6);
			break;
		}
	} while (c != 4);
}

void MyGame::Start() {
	Menu(6);
}

void MyGame::playWithPlayer() {
	DeleteArea(8, 50, 0, 0);
	GotoXY(0, 0);

	int turn = 1;
	int x = 0, y = 0;
	short current_point_x, current_point_y;

	coutWithColor("Player 1 = X\n", 12);
	coutWithColor("Player 2 = O", 11);

	SetColor(6);

	ChessTable chessTable(2, 1);
	chessTable.display();
	do {
		do {
			chessTable.gotoChessBox(11, 0);

			if (turn == 1) SetColor(12);
			else SetColor(11);
			cout << "Player " << turn << "'s turn: ";
			current_point_x = GetX();
			current_point_y = GetY();
			cin >> x >> y;
			DeleteArea(1, 10, current_point_x, current_point_y);
		} while (chessTable.status->value[x][y]);

		SetColor(6);
		chessTable.draw(x, y, turn);

		if (turn == 1) turn++;
		else turn--;
	} while (chessTable.checkWin(chessTable.status, x, y) == 0);

	saveGame(chessTable.status);

	DeleteArea(50, 50, 0, 0);
	GotoXY(0, 0);
	if (chessTable.checkWin(chessTable.status, x, y) == 1) SetColor(12);
	else SetColor(11);
	cout << "Player " << chessTable.checkWin(chessTable.status, x, y) << " win" << endl;
	SetColor(6);
	char c;
	do {
		cout << "Press 'c' to continue: "; cin >> c;
	} while (c != 'c');

	Menu(6);
}

void copyMatrix(Matrix* a, Matrix* b) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			a->value[i][j] = b->value[i][j];
		}
	}
}

void MyGame::saveGame(Matrix* m) {
	for (int i = NUMBER_OF_GAME_REPLAY - 1; i >= 1; i--) {
		copyMatrix(replayGames[i], replayGames[i - 1]);
	}
	copyMatrix(replayGames[0], m);
}

void MyGame::replay() {
	DeleteArea(50, 50, 0, 0);
	GotoXY(0, 0);

	SetColor(6);
	cout << "*--------------REPLAY------------*" << endl;

	for (int i = 0; i < NUMBER_OF_GAME_REPLAY; i++) {
		displayOldGame(replayGames[i], i);
	}
}

void MyGame::displayOldGame(Matrix* m, int index) {
	SetColor(3 * index + 1);
	GotoXY(index * 50, 5);
	ChessTable cb(2, index * 10 + index + 1);
	cb.display();

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if(m->value[i][j] == 1 || m->value[i][j] == 2) 
				cb.draw(i, j, m->value[i][j]);
		}
	}

	if (index == NUMBER_OF_GAME_REPLAY - 1) {
		SetColor(6);
		GotoXY(25, 25);
		cout << endl;
		char c;
		do {
			cout << "Press 'm' to back MAIN MENU: "; cin >> c;
		} while (c != 'm');
		DeleteArea(35, 135, 0, 0);
		Menu(6);
	}
}

void MyGame::Guild() {
	DeleteArea(50, 50, 0, 0);
	GotoXY(0, 0);
	SetColor(6);

	cout << "*--------------HOW TO PLAY------------*" << endl << endl;
	cout << "1. Lan luot nhap toa do (so _dong so_cot)\n";
	cout << "2. Neu ben nao co " << CONDITION_WIN + 1 << " quan co cua minh giong nhau lien tiep thi se thang\n";
	cout << endl;
	char c;
	do {
		cout << "Press 'm' to back MAIN MENU: "; cin >> c;
	} while (c != 'm');
	Menu(6);
}