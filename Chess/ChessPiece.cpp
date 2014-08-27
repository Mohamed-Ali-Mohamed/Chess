#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
using namespace sf;

#include"ChessBoard.h"
bool ChessPiece::GetWhite()
{
	return white;
}
void ChessPiece::SetWhite(bool input)
{
	white=input;
}
string ChessPiece::GetName()
{
	return name;
}
void ChessPiece::SetName(string input)
{
	name=input;
}
ChessPiecePosition ChessPiece::GetPosition()
{
	return position;
}
void ChessPiece::SetPosition(ChessPiecePosition input)
{
	position=input;
}

vector<Possible_Move> ChessPiece::move()
{
	vector<Possible_Move> All_Possible_Positions;
	return All_Possible_Positions;
}

