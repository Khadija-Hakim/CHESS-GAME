#include"Piece.h"
#pragma once

class Knight : public Piece
	{
	public:
		Knight(int r, int c, char s, COLOR clr, Board* ab);
		virtual bool IsLegalMove(Position ep)override;

	};



