#include "Queen.h"
Queen::Queen(int r, int c, char s, COLOR clr, Board* ab) :Piece(r, c, s, clr,ab)
{

}
bool Queen::IsLegalMove(Position ep) 
{
	 return 
		 (IsVerticalMove(this->pos, ep) && IsVerticalPathClear(this->pos, ep))
									||
		 (IsHorizonMove(this->pos, ep) && IsHorizonPathClear(this->pos, ep))
									||
		 (IsDiagonalMove(this->pos, ep) && IsDiagonalPathClear(this->pos, ep));
}