#include "Bishop.h"
Bishop::Bishop(int r, int c, char s, COLOR clr, Board* ab) :Piece(r, c, s, clr,ab)
{

}
bool Bishop::IsLegalMove(Position ep) 
{
	return (IsDiagonalMove(this->pos, ep) && IsDiagonalPathClear(this->pos, ep));
}