#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

#include "ChessTable.h"
#include "MyConsole.h"

#define NUMBER_OF_GAME_REPLAY 3

using namespace std; 
#pragma once
class MyGame
{
	Matrix** replayGames;
public:
	MyGame();

	void Start();
	void Menu(WORD color);
	void menuPlayWithBOT(WORD color);
	void End();

	void playWithPlayer();
	void Guild();

	void saveGame(Matrix* m);

	void displayOldGame(Matrix* m);
};
