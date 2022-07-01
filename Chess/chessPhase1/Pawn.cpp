#include "Pawn.h"

Pawn::Pawn(int r, int c, char s, COLOR clr, Board* ab) :Piece(r, c, s, clr,ab)
{

}
bool Pawn::IsLegalMove(Position ep) 
{
	return true;
}