#include"Piece.h"
#pragma once

class Queen:public Piece
{
public:
	Queen(int r, int c, char s, COLOR clr, Board* ab);
	virtual bool IsLegalMove(Position ep)override;
};

