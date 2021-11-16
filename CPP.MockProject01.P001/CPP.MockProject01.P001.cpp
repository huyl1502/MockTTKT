#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

#include "MyConsole.h"
#include "ChessTable.h"
#include "MyGame.h"

using namespace std;

void menu(WORD color) {
	SetColor(color);
	cout << "*--------------MAIN MENU------------*" << endl;
	cout << "Press number to choose" << endl;
	cout << "1.Play with other player" << endl;
	cout << "2.Play with BOT" << endl;
	cout << "3.Play with other player" << endl;
	cout << "4.Play with other player" << endl;

}
int main()
{
	MyGame* game = new MyGame();
	game->Start();

	return 0;
}

