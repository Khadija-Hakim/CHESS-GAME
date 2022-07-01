#include"Piece.h"
#pragma once

class King :public Piece
{
public:
	King(int r, int c, char s, COLOR clr, Board* ab);
	virtual bool IsLegalMove(Position ep)override;
};

