#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

#include "MyConsole.h"
#include "ChessTable.h"
#include "MyGame.h"

using namespace std;

int main()
{
	MyGame* game = new MyGame();
	game->Start();

	return 0;
}

