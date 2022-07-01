#include "Knight.h"
Knight::Knight(int r, int c, char s, COLOR clr, Board* ab) :Piece(r, c, s, clr,ab)
{

}
bool Knight:: IsLegalMove(Position ep) 
{
	int dr = abs(ep.ri - this->pos.ri),
	    dc = abs(ep.ci - this->pos.ci);

	return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
}