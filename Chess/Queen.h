#ifndef QUEEN_H
#define QUEEN_H
#include"ChessPiece.h"
class Queen : public ChessPiece
{
public:
	Queen (){}
	~Queen (){}
	void Draw(RenderWindow &window);
	vector<Possible_Move> move();
private:
};
#endif