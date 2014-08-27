#ifndef PAWN_H
#define PAWN_H
#include"ChessPiece.h"
class Pawn : public ChessPiece
{
public:
	Pawn (){}
	~Pawn (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
private:
};
#endif