#include"Bishop.h"
#include"ChessBoard.h"
#include"GLOBALS.h"

vector<Possible_Move> Bishop::move()
{
	ChessPiecePosition current_position;
	Possible_Move possible_move;
	///////////////////////////////////////
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> All_Possible_Positions;
	current_position = GetPosition();
	bool Current_White = GetWhite();
	//Up-Right
	int y=current_position.y;
	int x=current_position.x;
	while(y>0 && x<7)
	{
		y--;
		x++;
		ChessPiece NewPiece = *Board[y][x];
		ChessPiecePosition p;
		p.x=x;
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
			y=0;
			break;
		}

	}
	//Up-Left
	y=current_position.y;
	x=current_position.x;
	while(y>0 && x>0)
	{
		y--;
		x--;
		ChessPiece NewPiece = *Board[y][x];
		ChessPiecePosition p;
		p.x=x;
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
			y=0;
			break;
		}

	}
	//Down-Right
	y=current_position.y;
	x=current_position.x;
	while(y<7 && x<7)
	{
		y++;
		x++;
		ChessPiece NewPiece = *Board[y][x];
		ChessPiecePosition p;
		p.x=x;
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
			y=8;
			break;
		}

	}
	//Down-Left
	y=current_position.y;
	x=current_position.x;
	while(y<7 && x>0)
	{
		y++;
		x--;
		ChessPiece NewPiece = *Board[y][x];
		ChessPiecePosition p;
		p.x=x;
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
			y=8;
			break;
		}

	}
	return All_Possible_Positions;
}
void Bishop::Draw(RenderWindow &window)
{
	Texture texture;
	Sprite sprite;
	if(this->GetWhite())
		texture.loadFromFile("Graphics\\BishopW.png");
	else
		texture.loadFromFile("Graphics\\BishopB.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->GetPosition().x * Board_Square_Width,this->GetPosition().y * Board_Square_Height);
	window.draw(sprite);
}