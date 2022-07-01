#include"Piece.h"
#pragma once

class Rook: public Piece
{
public:
	Rook(int r, int c, char s, COLOR clr, Board* ab);
	virtual bool IsLegalMove(Position ep) override;

};

