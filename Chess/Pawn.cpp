#include"Pawn.h"
#include"ChessBoard.h"
#include"GLOBALS.h"
vector<Possible_Move> Pawn::move(){
	ChessPiecePosition current_position;
	Possible_Move possible_move;
	///////////////////////////////////////
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> All_Possible_Positions;
	current_position = GetPosition();
	bool Current_White = GetWhite();
	//Up
	if(Current_White)
	{
		if(current_position.y!=0)
		{
			////Up
			ChessPiece NewPiece =* Board[current_position.y-1][current_position.x];
			ChessPiecePosition p;
			p.x=current_position.x;
			p.y=current_position.y-1;
			if(NewPiece.GetName() == "")
			{
				if(p.y==0)
				{
					possible_move.position=p;
					possible_move.Action=GLOBALS::Action_MoveAndChange;
					All_Possible_Positions.push_back(possible_move);
				}
				else
				{
					possible_move.position=p;
					possible_move.Action=GLOBALS::Action_Move;
					All_Possible_Positions.push_back(possible_move);
				}
			}
			////Up 1
			if(current_position.y==6)
			{
				NewPiece = *Board[current_position.y-2][current_position.x];
				p.x=current_position.x;
				p.y=current_position.y-2;
				if(NewPiece.GetName() == "")
				{
					possible_move.position=p;
					possible_move.Action=GLOBALS::Action_Move;
					All_Possible_Positions.push_back(possible_move);

				}
			}
			////Up-Left
			if(current_position.x!=0)
			{
				ChessPiece NewPiece = *Board[current_position.y-1][current_position.x-1];
				ChessPiecePosition p;
				p.x=current_position.x-1;
				p.y=current_position.y-1;
				if(NewPiece.GetName() != "" && NewPiece.GetWhite() != Current_White)
				{
					if(p.y==0)
					{
						possible_move.position=p;
						possible_move.Action=GLOBALS::Action_AttackAndChange;
						All_Possible_Positions.push_back(possible_move);
					}
					else
					{
						possible_move.position=p;
						possible_move.Action=GLOBALS::Action_Attack;
						All_Possible_Positions.push_back(possible_move);
					}
				}
			}
			////Up-Right
			if(current_position.x!=7)
			{
				ChessPiece NewPiece = *Board[current_position.y-1][current_position.x+1];
				ChessPiecePosition p;
				p.x=current_position.x+1;
				p.y=current_position.y-1;
				if(NewPiece.GetName() != "" && NewPiece.GetWhite() != Current_White)
				{
					if(p.y==0)
					{
						possible_move.position=p;
						possible_move.Action=GLOBALS::Action_AttackAndChange;
						All_Possible_Positions.push_back(possible_move);
					}
					else
					{
						possible_move.position=p;
						possible_move.Action=GLOBALS::Action_Attack;
						All_Possible_Positions.push_back(possible_move);
					}
				}
			}
		}
	}
	//Down
	else
	{
		if(current_position.y!=7)
		{
			////Down
			ChessPiece NewPiece = *Board[current_position.y+1][current_position.x];
			ChessPiecePosition p;
			p.x=current_position.x;
			p.y=current_position.y+1;
			if(NewPiece.GetName() == "")
			{
				if(p.y==7)
				{
					possible_move.position=p;
					possible_move.Action=GLOBALS::Action_MoveAndChange;
					All_Possible_Positions.push_back(possible_move);
				}
				else
				{
					possible_move.position=p;
					possible_move.Action=GLOBALS::Action_Move;
					All_Possible_Positions.push_back(possible_move);
				}
			}
			////Down 1
			if(current_position.y==1)
			{
				NewPiece = *Board[current_position.y+2][current_position.x];
				p.x=current_position.x;
				p.y=current_position.y+2;
				if(NewPiece.GetName() == "")
				{
					possible_move.position=p;
					possible_move.Action=GLOBALS::Action_Move;
					All_Possible_Positions.push_back(possible_move);

				}
			}
			////Down-Left
			if(current_position.x!=0)
			{
				ChessPiece NewPiece = *Board[current_position.y+1][current_position.x-1];
				ChessPiecePosition p;
				p.x=current_position.x-1;
				p.y=current_position.y+1;
				if(NewPiece.GetName() != "" && NewPiece.GetWhite() != Current_White)
				{
					if(p.y==7)
					{
						possible_move.position=p;
						possible_move.Action=GLOBALS::Action_AttackAndChange;
						All_Possible_Positions.push_back(possible_move);
					}
					else
					{
						possible_move.position=p;
						possible_move.Action=GLOBALS::Action_Attack;
						All_Possible_Positions.push_back(possible_move);
					}
				}
			}
			////Down-Right
			if(current_position.x!=7)
			{
				ChessPiece NewPiece = *Board[current_position.y+1][current_position.x+1];
				ChessPiecePosition p;
				p.x=current_position.x+1;
				p.y=current_position.y+1;
				if(NewPiece.GetName() != "" && NewPiece.GetWhite() != Current_White)
				{
					if(p.y==7)
					{
						possible_move.position=p;
						possible_move.Action=GLOBALS::Action_AttackAndChange;
						All_Possible_Positions.push_back(possible_move);
					}
					else
					{
						possible_move.position=p;
						possible_move.Action=GLOBALS::Action_Attack;
						All_Possible_Positions.push_back(possible_move);
					}
				}
			}
		}
	}
	return All_Possible_Positions;
}
void Pawn::Draw(RenderWindow &window)
{
	Texture texture;
	Sprite sprite;
	if(this->GetWhite())
		texture.loadFromFile("Graphics\\PawnW.png");
	else
		texture.loadFromFile("Graphics\\PawnB.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->GetPosition().x * Board_Square_Width,this->GetPosition().y * Board_Square_Height);
	window.draw(sprite);
}