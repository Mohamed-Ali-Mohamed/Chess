#include<iostream>
#include<string>
#include<map>
using namespace std;
#include"ChessBoard.h"
#include"King.h"
#include"Bishop.h"
#include"Pawn.h"
#include"Knight.h"
#include"Queen.h"
#include"Rook.h"
vector<vector<ChessPiece* > > ChessBoard::Board = vector<vector<ChessPiece*> > ();
///////////////////////////////////////////////////////////////
ChessBoard::ChessBoard()
{
	Board.clear();
	Board.resize(8);
	for(int i=0 ; i<8 ; i++)
	{
		for(int j=0 ; j<8 ; j++)
		{
			ChessPiece* p =new ChessPiece();
			ChessPiecePosition position;
			position.x=j;position.y=i;
			p->SetPosition(position);
			Board[i].push_back(p);
		}
	}
	InBoard(false);
	InBoard(true);
}
void ChessBoard::InBoard(bool White)
{
	ChessPiecePosition current_position;
	////
	string InitBoard[2][8]={
		{"Rook","Knight","Bishop","Queen","King","Bishop","Knight","Rook"},
		{"Pawn","Pawn",  "Pawn",  "Pawn", "Pawn","Pawn",  "Pawn",  "Pawn"}};
	////

	for(int y=0 ; y<2 ; y++)
	{
		for(int x=0 ; x<8 ; x++)
		{
			Rook* rook = new Rook();
			Knight* knight = new Knight();
			Bishop* bishop = new Bishop();
			Queen* queen = new Queen();
			King* king = new King();
			Pawn* pawn = new Pawn();
			current_position.x=x;
			if(!White)
				current_position.y=y;
			else
				current_position.y=7-y;
			if(InitBoard[y][x]=="Rook")
			{
				rook->SetWhite(White);
				rook->SetName(InitBoard[y][x]);
				rook->SetPosition(current_position);
				Board[current_position.y][current_position.x] = rook;
			}
			else if(InitBoard[y][x]=="Knight")
			{
				knight->SetWhite(White);
				knight->SetName(InitBoard[y][x]);
				knight->SetPosition(current_position);
				Board[current_position.y][current_position.x] = knight;
			}
			else if(InitBoard[y][x]=="Bishop")
			{

				bishop->SetWhite(White);
				bishop->SetName(InitBoard[y][x]);
				bishop->SetPosition(current_position);
				Board[current_position.y][current_position.x] = bishop;
			}
			else if(InitBoard[y][x]=="Queen")
			{
				queen->SetWhite(White);
				queen->SetName(InitBoard[y][x]);
				queen->SetPosition(current_position);
				Board[current_position.y][current_position.x] = queen;
			}
			else if(InitBoard[y][x]=="King")
			{
				king->SetWhite(White);
				king->SetName(InitBoard[y][x]);
				king->SetPosition(current_position);
				Board[current_position.y][current_position.x] = king;
			}
			else if(InitBoard[y][x]=="Pawn")
			{
				pawn->SetWhite(White);
				pawn->SetName(InitBoard[y][x]);
				pawn->SetPosition(current_position);
				Board[current_position.y][current_position.x] = pawn;
			}
		}
	}
}
vector< vector<ChessPiece*> > ChessBoard::GetBoard()
{
	return Board;
}
void ChessBoard::SetBoard(vector< vector<ChessPiece*> > input)
{
	Board=input;
}