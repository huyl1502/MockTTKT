#include<iostream>
#include<string>
#include "Matrix.h" 
#include"MyConsole.h"

#define ROWS 10
#define COLS 10
#define CONDITION_WIN 3
using namespace std;
#pragma once
//quan ly ban co
class ChessTable 
{
	//toa do diem dau cua ChessTable, tinh theo box
	short m_X; // row
	short m_Y; // col
public:
	Matrix* status;
	//goc (0,0)
	ChessTable();
	// goc (row, col) (chess box)
	ChessTable(short row, short col);

	void display();
	
	void gotoChessBox(short row, short col);
	/* 
	 *hop le ->1
	 *o da duoc chon -> 0	
	 *toa do nam ngoai ban co -> -1
	*/
	short draw(short r, short c, short value); 
	
	// (r c) la toa do vua duoc chon 
	// 1: player 1; 2:player 2; 0: chua co ai thang
	int checkWin(Matrix* m, int r, int c);

	bool draw(Matrix& currentStatus);
};

