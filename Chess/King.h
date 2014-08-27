#ifndef KING_H
#define KING_H
#include"ChessPiece.h"
class King : public ChessPiece
{
public:
	King (){}
	~King (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
private:
};
#endif