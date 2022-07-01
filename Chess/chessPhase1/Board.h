#include"Piece.h"
#include<iostream>
#include<string>
#pragma once
class Board
{
	const int dim{ 8 };
	Piece* Ps[8][8];
	string Players[2];
	COLOR Turn;
	Position src, dst;
public:
	void LoadGame();
	void DisplayTurnMsg();
	void SelectSource();
	void SelectDestination();
	bool IsValidSelection();
	bool IsValidDestination();
	bool IsEmpty(int r, int c);
	void TurnChange();
	void Highlight();
	friend ostream& operator<<(ostream &, const Board&);
	void Play();
	void PieceMove(Position src, Position dst);

};

