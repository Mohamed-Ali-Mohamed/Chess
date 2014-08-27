#include"Rook.h"
#include"ChessBoard.h"
#include"GLOBALS.h"
vector<Possible_Move> Rook::move()
{
	ChessPiecePosition current_position;
	Possible_Move possible_move;
	///////////////////////////////////////
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> All_Possible_Positions;
	current_position = GetPosition();
	bool Current_White = GetWhite();
	//Right
	for(int x=current_position.x+1 ; x<8 ; x++)
	{
		ChessPiece NewPiece = *Board[current_position.y][x];
		ChessPiecePosition p;
		p.x=x;
		p.y=current_position.y;
		if(NewPiece.GetName() == "")
		{
			possible_move.position = p;
			possible_move.Action=GLOBALS::Action_Move;
			All_Possible_Positions.push_back(possible_move);
		}
		else
		{
			if(NewPiece.GetWhite() != Current_White)
			{
				possible_move.position=p;
				possible_move.Action=GLOBALS::Action_Attack;
				All_Possible_Positions.push_back(possible_move);
			}
			break;
		}
	}
	//Left
	for(int x=current_position.x-1 ; x>=0 ; x--)
	{
		ChessPiece NewPiece =* Board[current_position.y][x];
		ChessPiecePosition p;
		p.x=x;
		p.y=current_position.y;
		if(NewPiece.GetName() == "")
		{
			possible_move.position=p;
			possible_move.Action=GLOBALS::Action_Move;
			All_Possible_Positions.push_back(possible_move);
		}
		else
		{
			if(NewPiece.GetWhite() != Current_White)
			{
				possible_move.position=p;
				possible_move.Action=GLOBALS::Action_Attack;
				All_Possible_Positions.push_back(possible_move);
			}
			break;
		}
	}
	//Down
	for(int y=current_position.y+1 ; y<8 ; y++)
	{
		ChessPiece NewPiece = *Board[y][current_position.x];
		ChessPiecePosition p;
		p.x=current_position.x;
		p.y=y;
		if(NewPiece.GetName() == "")
		{
			possible_move.position=p;
			possible_move.Action=GLOBALS::Action_Move;
			All_Possible_Positions.push_back(possible_move);
		}
		else
		{
			if(NewPiece.GetWhite() != Current_White)
			{
				possible_move.position=p;
				possible_move.Action=GLOBALS::Action_Attack;
				All_Possible_Positions.push_back(possible_move);
			}
			break;
		}
	}
	//Up
	for(int y=current_position.y-1 ; y>=0 ; y++)
	{
		ChessPiece NewPiece = *Board[y][current_position.x];
		ChessPiecePosition p;
		p.x=current_position.x;
		p.y=y;
		if(NewPiece.GetName() == "")
		{
			possible_move.position=p;
			possible_move.Action=GLOBALS::Action_Move;
			All_Possible_Positions.push_back(possible_move);
		}
		else
		{
			if(NewPiece.GetWhite() != Current_White)
			{
				possible_move.position=p;
				possible_move.Action=GLOBALS::Action_Attack;
				All_Possible_Positions.push_back(possible_move);
			}
			break;
		}
	}
	return All_Possible_Positions;
}
void Rook::Draw(RenderWindow &window)
{
	Texture texture;
	Sprite sprite;
	if(this->GetWhite())
		texture.loadFromFile("Graphics\\RookW.png");
	else
		texture.loadFromFile("Graphics\\RookB.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->GetPosition().x * Board_Square_Width,this->GetPosition().y * Board_Square_Height);
	window.draw(sprite);
}