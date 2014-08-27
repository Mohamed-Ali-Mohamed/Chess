#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
////
#include<string>
#include<vector>
using namespace std;
using namespace sf;
struct ChessPiecePosition
{
	int x,y;
};
struct Possible_Move
{
	ChessPiecePosition position;
	string Action;
};

class ChessPiece
{
	bool white;
	string name;
	ChessPiecePosition position;
public:
	ChessPiece(){}
	~ChessPiece(){}
	bool GetWhite();
	void SetWhite(bool input);
	string GetName();
	void SetName(string input);
	ChessPiecePosition GetPosition();
	void SetPosition(ChessPiecePosition input);
	virtual void Draw(RenderWindow &window){}
	virtual vector<Possible_Move> move();
private:
};
#endif

