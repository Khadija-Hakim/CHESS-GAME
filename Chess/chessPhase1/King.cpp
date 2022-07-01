#include "King.h"
King::King(int r, int c, char s, COLOR clr, Board* ab) :Piece(r, c, s, clr,ab)
{

}
bool King:: IsLegalMove(Position ep) 
{
	int dr = abs(ep.ri - this->pos.ri),
	    dc = abs(ep.ci - this->pos.ci);

	return dr <= 1 && dc <= 1;
}