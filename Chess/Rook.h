#ifndef ROOK_H
#define ROOK_H
#include"ChessPiece.h"
class Rook : public ChessPiece
{
public:
	Rook (){}
	~Rook (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
private:
};
#endif