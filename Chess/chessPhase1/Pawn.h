#include "Piece.h"
#pragma once

class Pawn : public Piece
{
public:
	Pawn ( int r, int c, char s, COLOR clr, Board* ab);
	virtual bool IsLegalMove(Position ep) override;
};

