#ifndef KNIGHT_H
#define KNIGHT_H
#include"ChessPiece.h"
class Knight : public ChessPiece
{
public:
	Knight (){}
	~Knight (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
private:
};
#endif