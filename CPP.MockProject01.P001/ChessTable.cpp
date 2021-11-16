#include "ChessTable.h"

ChessTable::ChessTable() {
	m_X = 1;
	m_Y = 1;
	status = new Matrix(ROWS, COLS);
}
ChessTable::ChessTable(short row, short col) {
	m_X = row;
	m_Y = col;
	status = new Matrix(ROWS, COLS);
}
void ChessTable::display() {
	//in cac index of ban co
	for (int i = 0; i < COLS; i++) {
		DrawChess(m_X - 1, m_Y + i, i + 48);
		DrawChess(m_X + i, m_Y - 1, i + 48);
	}

	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++) {
			DrawBox(i + m_X, j + m_Y);
		}
	gotoChessBox(ROWS , m_Y);
}

short ChessTable::draw(short i, short j, short value) {
	//value = 1 : X      value = 2: O
	if (value == 1) SetColor(12);
	else SetColor(11);

	short mark = status->getValue(i, j);
	if (mark == NULL) {
		char chess = value == 1 ? 'X' : value == 2 ? 'O' : 'E';
		status->add(i , j , value);
		DrawChess(i + m_X, j + m_Y, chess);
		//ve thanh cong
		return 1;
	}
	else if (mark) {
		//BAO LOI 
		return 0;
	}
	return mark;
}
void ChessTable::gotoChessBox(short row, short col) {
	short topX = _LENGTH_HORIZONTAL * (col+ m_Y);
	short topY = _LENGTH_VERTICAL * (row + m_X);
	GotoXY(topX + _LENGTH_HORIZONTAL / 2, topY + 1);
}


// 1: player 1; 2:player 2; 0: chua co ai thang
//Kiem tra ai thang
int playerWin(int count, short v) {
	if (count == CONDITION_WIN) return v;
	else return 0;
}

//Kiem tra thang theo hang
int horizontalWin(Matrix* m, int x, int y) {
	//left count, right count
	int lcount = 0, rcount = 0;

	for (int j = y + 1; j < COLS; j++) {
		if (m->value[x][j] == m->value[x][y]) rcount++;
	}

	for (int j = y - 1; j >= 0; j--) {
		if (m->value[x][j] == m->value[x][y]) lcount++;
	}

	return playerWin(rcount + lcount, m->value[x][y]);
}

//Kiem tra thang theo cot
int verticalWin(Matrix* m, int x, int y) {
	//up count, down count
	int ucount = 0, dcount = 0;

	for (int i = x + 1; i < ROWS; i++) {
		if (m->value[i][y] == m->value[x][y]) dcount++;
	}

	for (int i = x - 1; i >= 0; i--) {
		if (m->value[i][y] == m->value[x][y]) ucount++;
	}

	return playerWin(ucount + dcount, m->value[x][y]);
}

//Kiem tra thang theo duong cheo chinh
int mDiagonalWin(Matrix* m, int x, int y) {
	//left up, right down
	int lucount = 0, rdcount = 0;

	for (int i = x + 1; i < ROWS; i++) {
		for (int j = y + 1; j < COLS; j++) {
			if (j - y == i - x) {
				if (m->value[i][j] == m->value[x][y]) rdcount++;
			}
			else continue;
		}
	}

	for (int i = x - 1; i >= 0; i--) {
		for (int j = y - 1; j >= 0; j--) {
			if (y - j == x - i) {
				if (m->value[i][j] == m->value[x][y]) lucount++;
			}
			else continue;
		}
	}

	return playerWin(rdcount + lucount, m->value[x][y]);
}

//Kiem tra thang theo duong cheo phu
int aDiagonalWin(Matrix* m, int x, int y) {
	//right up, left down
	int rucount = 0, ldcount = 0;

	for (int i = x + 1; i < ROWS; i++) {
		for (int j = y - 1; j >= 0; j--) {
			if (y - j == i - x) {
				if (m->value[i][j] == m->value[x][y]) rucount++;
			}
			else continue;
		}
	}

	for (int i = x - 1; i >= 0; i--) {
		for (int j = y + 1; j < COLS; j++) {
			if (j - y == x - i) {
				if (m->value[i][j] == m->value[x][y]) ldcount++;
			}
			else continue;
		}
	}

	return playerWin(rucount + ldcount, m->value[x][y]);
}

int ChessTable::checkWin(Matrix* m, int x, int y) {
	int hw = horizontalWin(m, x, y);
	int vw = verticalWin(m, x, y);
	int mdw = mDiagonalWin(m, x, y);
	int adw = aDiagonalWin(m, x, y);

	if (hw) return hw;
	if (vw) return vw;
	if (mdw) return mdw;
	if (adw) return adw;

	return 0;
}
