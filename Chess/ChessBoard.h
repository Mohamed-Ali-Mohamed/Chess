#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include"ChessPiece.h"
#include<vector>
using namespace std;
class ChessBoard
{
	ChessPiece Piece;
	static vector< vector<ChessPiece*> > Board ;
public:
	ChessBoard();
	~ChessBoard(){}
	static vector< vector<ChessPiece*> >  GetBoard();
	static void SetBoard(vector< vector<ChessPiece*> > input);
private:
	void InBoard(bool White);
};

#endif