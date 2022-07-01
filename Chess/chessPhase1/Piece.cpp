#include "Piece.h"
#include "Board.h"
#include<iostream>
using namespace std;

Piece::Piece(int r, int c, char s, COLOR cl, Board* ab) : pos{ r,c }, sym{ s }, clr{ cl }
{
	this->b = ab;
}
ostream& operator<<(ostream &, const Piece& P) 
{
	return cout << P.sym << "\t";
}
void Piece::UpdatePosition(Position P) 
{
	Position prev = this->pos;
	this->pos = P;
	b->PieceMove(prev,P);
}
COLOR Piece::GetColor() 
{
	return this->clr;
}
bool Piece::IsHorizonMove(Position sp, Position ep)
{
	return sp.ri = ep.ri;
}
bool Piece::IsVerticalMove(Position sp, Position ep) 
{
	return sp.ci = ep.ci;
}
bool Piece::IsDiagonalMove(Position sp, Position ep) 
{
	int dr = abs(sp.ri - ep.ri);
	int dc = abs(sp.ci - ep.ci);

	return (dr == dc);
}
bool Piece::IsHorizonPathClear(Position sp, Position ep) 
{
	int dc = ep.ci - ep.ci;
	if (dc > 0)          //  Going from left to right... 
	{
		for (int c = sp.ci + 1;c < ep.ci;c++)
		{
			if (!b->IsEmpty(sp.ri,c))
				return false;
		}
		return true;
	}
	else				//   Going from bottom to top
	{
		for (int c = ep.ci + 1;c < ep.ci;c++)
		{
			if (!b->IsEmpty(sp.ri, c))
				return false;
		}
		return true;
	}
}
bool Piece::IsVerticalPathClear(Position sp, Position ep)
{
	int dr = ep.ri - sp.ri;
	if (dr > 0)          //  Going from top to bottom 
	{
		for (int r = sp.ri + 1;r < ep.ri;r++) 
		{
			if (!b->IsEmpty(r, sp.ci))
				return false;
		}
		return true;
	}
	else				//   Going from bottom to top
	{
		for (int r = ep.ri + 1;r < sp.ri;r++)
		{
			if (!b->IsEmpty(r, sp.ci))
				return false;
		}
		return true;
	}
}
bool Piece::IsDiagonalPathClear(Position sp, Position ep)
{
	int dr = ep.ri - sp.ri;
	int dc = ep.ci - sp.ci;
	if (dr == dc)                   //    "Diagonal \"
	{
		if (dr > 0)                //     Going from top to bottom
		{
			for (int d = 1;d < dr;d++) 
			{
				if (!b->IsEmpty(sp.ri + d, sp.ci + d))
					return false;
			}
			return true;
		}
		else                      // Going from bottom to top
		{
			for (int d = 1;d < dr;d++)
			{
				if (!b->IsEmpty(ep.ri + d, ep.ci + d))
					return false;
			}
			return true;
		}
	}
	
	else                           //     "Diagonal /"
	{
		if (dr > 0)
		{
			for (int d = 1;d < dr;d++)
			{
				if (!b->IsEmpty(sp.ri + d, sp.ci - d))
					return false;
			}
			return true;
		}
		else
		{
			for (int d = 1;d < dr;d++)
			{
				if (!b->IsEmpty(ep.ri + d, ep.ci - d))
					return false;
			}
			return true;
		}
	}
}