#include<fstream>
#include<iostream>
#include<conio.h>
using namespace std;
#include "Board.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
void Board:: LoadGame() 
{
	ifstream Rdr("Text.txt");

	for (int ri = 0; ri < dim; ri++) 
	{
		for (int ci = 0;ci < dim;ci++) 
		{
			char sym;
			Rdr >> sym;
			switch (sym) 
			{
			case 'P':
				Ps[ri][ci] = new Pawn(ri,ci,sym,BLACK,this); break;
			case 'p':
				Ps[ri][ci] = new Pawn(ri, ci, sym, WHITE, this); break;
			case 'R':
				Ps[ri][ci] = new Rook(ri, ci, sym, BLACK, this); break;
			case 'r':
				Ps[ri][ci] = new Rook(ri, ci, sym, WHITE, this); break;
			case 'B':
				Ps[ri][ci] = new Bishop(ri, ci, sym, BLACK, this); break;
			case 'b':
				Ps[ri][ci] = new Bishop(ri, ci, sym, WHITE, this); break;
			case 'K':
				Ps[ri][ci] = new King(ri, ci, sym, BLACK, this); break;
			case 'k':
				Ps[ri][ci] = new King(ri, ci, sym, WHITE, this); break;
			case 'Q':
				Ps[ri][ci] = new Queen(ri, ci, sym, BLACK, this); break;
			case 'q':
				Ps[ri][ci] = new Queen(ri, ci, sym, WHITE, this); break;
			case 'H':
				Ps[ri][ci] = new Knight(ri, ci, sym, BLACK, this); break;
			case 'h':
				Ps[ri][ci] = new Knight(ri, ci, sym, WHITE, this); break;
			default:
				Ps[ri][ci] = nullptr;
			}

		}
	}
	cout << "Player 1's name: ";
	cin >> Players[0];
	cout << "Player 2's name: ";
	cin >> Players[1];

}
bool Board:: IsEmpty(int r, int c) 
{
	return Ps[r][c] == nullptr;
}
void Board:: DisplayTurnMsg() 
{
	cout << Players[Turn] << "'s Turn\n\n";
}
void Board::SelectSource()
{
	cin >> src.ri >> src.ci;
}
void Board::SelectDestination() 
{
	cin >> dst.ri >> dst.ci;
}
bool Board::IsValidSelection() 
{
	if (src.ri < 0 || src.ri>7 || src.ci < 0 || src.ci>7)
		return false;
	return (Ps[src.ri][src.ci] != nullptr && Ps[src.ri][src.ci]->GetColor() == Turn);
}
bool Board::IsValidDestination()
{
	return (dst.ri >= 0 && dst.ri<=7 && dst.ci >= 0 && dst.ci<=7) && (Ps[dst.ri][dst.ci] == nullptr || Ps[dst.ri][dst.ci]->GetColor() != Turn);
}
void Board::TurnChange() 
{
	Turn=(Turn==BLACK ? WHITE:BLACK);
}
void Board::PieceMove(Position src, Position dst)
{
	this->Ps[dst.ri][dst.ci] = this->Ps[src.ri][src.ci];
	this->Ps[src.ri][src.ci] = nullptr;
}
void Board::Highlight() 
{
	system("cls");
	for (int r = 0;r < dim;r++) 
	{
		for (int c = 0;c < dim;c++)
		{
			Position tdest{ r, c };
			dst = tdest;
			if (IsValidDestination() && Ps[src.ri][src.ci]->IsLegalMove(tdest))
			{
				cout << "x" << "\t";
			}
			else if ((Ps[tdest.ri][tdest.ci])== nullptr) 
			{
				cout << "-" << "\t";
			}
			else
			{
				cout << *(Ps[tdest.ri][tdest.ci]);
			}

		}
		cout << endl;
	}
}
void Board::Play()
{
	Turn = BLACK;
	do
	{
		DisplayTurnMsg();
		do
		{
			do
				{
					do
						{
							SelectSource();
							if (IsValidSelection() == false)
							cout << "Invalid Selection....!!!!\n\n Select source again !\n";
							cout << "Press any key to continue";
							_getch();
							cout << *this;
			} while (IsValidSelection() == false);
			Highlight();
			SelectDestination();
			if (IsValidDestination() == false)
			{
				cout << "Invalid Destination....!!!!\n\n Select destination again !\n";
				cout << "Press any key to continue";
				_getch();
				cout << *this;
			}
		} while (IsValidDestination() == false);
		if (!Ps[src.ri][src.ci]->IsLegalMove(dst))
		{
			cout << "Illegal Move.......Select Again....!!!\n\n";
			cout << "Press any key to continue";
			_getch();
			cout << *this;
		}
		} while (!Ps[src.ri][src.ci]->IsLegalMove(dst));
		Ps[src.ri][src.ci]->UpdatePosition(dst);
		cout << *this;
		TurnChange();
	} while (true);
}
ostream& operator<<(ostream &, const Board& B)
{
	system("cls");
	for (int ri = 0; ri < B.dim; ri++)
	{
		for (int ci = 0;ci < B.dim;ci++)
		{
			if (B.Ps[ri][ci] == nullptr) 
			{
				cout << "-" << "\t";
			}
			else 
				cout << *(B.Ps[ri][ci]);
		}
		cout << endl;
	}
	return cout;
}