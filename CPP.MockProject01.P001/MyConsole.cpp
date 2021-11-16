#include "MyConsole.h"


void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

//BOOL WINAPI SetConsoleScreenBufferSize(
//	_In_ HANDLE hConsoleOutput,
//	_In_ COORD  dwSize
//);

//typedef struct _COORD {
//	SHORT X;
//	SHORT Y;
//} COORD, *PCOORD;
void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}
void GotoXY(short col, short row) {
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { col, row };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
short GetX() {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}
short GetY() {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}

/*
0 = Black	8 = Gray
1 = Blue	9 = Light Blue
2 = Green	10 = Light Green
3 = Aqua	11 = Light Aqua
4 = Red		12 = Light Red
5 = Purple	13 = Light Purple
6 = Yellow	14 = Light Yellow
7 = White	15 = Bright White
*/
void SetColor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void SetBackgroundColor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void DrawBox(short row, short col) {
	int topX = _LENGTH_HORIZONTAL * col;
	int topY = _LENGTH_VERTICAL * row;
	//x col, y row
	GotoXY(topX, topY); cout << "|---|";	//TOP
	GotoXY(topX, topY + 1); cout << "|";	//LEFT
	GotoXY(topX + _LENGTH_HORIZONTAL, topY + 1); cout << "|";	//RIGHT
	GotoXY(topX, topY + 2); cout << "|---|";//BOTTOM
}

void DrawChess(short row, short col, char chess) {
	int topX = _LENGTH_HORIZONTAL * col;
	int topY = _LENGTH_VERTICAL * row;
	GotoXY(topX + _LENGTH_HORIZONTAL / 2, topY + 1);
	cout << chess;
}

void DeleteArea(short rows, short cols, short topX, short topY) {
	SetColor(0);
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
		{
			GotoXY(j + topX, i + topY);
			cout << "E";
		}
}

void coutWithColor(string input, WORD color) {
	SetColor(color);
	cout << input;
}