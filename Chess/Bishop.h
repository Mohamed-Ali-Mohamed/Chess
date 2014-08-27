#ifndef BISHOP_H
#define BISHOP_H
#include"ChessPiece.h"
class Bishop : public ChessPiece
{
public:
	Bishop (){}
	~Bishop (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
private:
};
#endif