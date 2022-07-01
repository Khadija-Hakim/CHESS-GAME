#include "Rook.h"

Rook::Rook(int r, int c, char s, COLOR clr, Board* ab) :Piece(r, c, s, clr,ab)
{

}
bool Rook::IsLegalMove(Position ep)
{
	return (IsVerticalMove(this->pos, ep) && IsVerticalPathClear(this->pos,ep)) || (IsHorizonMove(this->pos,ep) && IsHorizonPathClear(this->pos,ep));
}