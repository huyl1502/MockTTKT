#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

#include "ChessTable.h"
#include "MyConsole.h"

using namespace std; 
#pragma once
class MyGame
{
	
public:
	void Start();
	void Menu(WORD color);
	void End();
};

void playWithPlayer();
