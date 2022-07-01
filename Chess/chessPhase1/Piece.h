#pragma once
#include<iostream>
using namespace std;
enum COLOR { BLACK, WHITE };	

struct Position
{
	int ri, ci;
};
class Board;
class Piece
{
protected:
	char sym;
	COLOR clr;
	Position pos;
	Board* b;
	bool IsHorizonMove(Position sp, Position ep);
	bool IsVerticalMove(Position sp, Position ep);
	bool IsDiagonalMove(Position sp, Position ep);
	bool IsHorizonPathClear(Position sp, Position ep);
	bool IsVerticalPathClear(Position sp, Position ep);
	bool IsDiagonalPathClear(Position sp, Position ep);
public:
	Piece(int r, int c, char s, COLOR clr, Board* ab);
	void UpdatePosition(Position P);
	virtual bool IsLegalMove(Position ep) = 0;
	friend ostream& operator<<(ostream &, const Piece&);
	COLOR GetColor();
};

