#include"Piece.h"
#pragma once

class Bishop : public Piece
{
public:
	Bishop(int r, int c, char s, COLOR clr, Board* ab);
	virtual bool IsLegalMove(Position ep)override;
};


