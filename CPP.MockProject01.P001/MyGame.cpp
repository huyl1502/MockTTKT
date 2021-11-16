#include "MyGame.h"
#include "ChessTable.h"
#include "MyConsole.h"

void MyGame::Menu(WORD color) {
	/*SetColor(color);

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
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		}
	} while (c != 6);*/

	playWithPlayer();
}

void Guild(WORD color) {
	SetColor(color);
	cout << "*--------------HOW TO PLAY------------*" << endl;
}

void menuPlayWithBOT(WORD color) {
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
			break;
		}
	} while (c != 4);
}

void MyGame::Start() {
	Menu(12);
}

void playWithPlayer() {
	int turn = 1;
	int x = 0, y = 0;
	short current_point_x, current_point_y;

	coutWithColor("Player 1 = X\n", 12);
	coutWithColor("Player 2 = O", 11);

	SetColor(6);

	ChessTable chessTable(2, 1);
	chessTable.display();
	do {
		chessTable.gotoChessBox(10, 0);

		cout << endl;
		if (turn == 1) SetColor(12);
		else SetColor(11);
		cout << "Player " << turn << "'s turn: "; 
		current_point_x = GetX();
		current_point_y = GetY();
		cin >> x >> y;

		DeleteArea(1, 3, current_point_x, current_point_y);

		SetColor(6);
		chessTable.draw(x, y, turn);

		if (turn == 1) turn++;
		else turn--;
	} while (chessTable.checkWin(chessTable.status, x, y) == 0);
}