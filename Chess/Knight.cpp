#include"Knight.h"
#include"ChessBoard.h"
#include"GLOBALS.h"
vector<Possible_Move> Knight::move()
{
	ChessPiecePosition current_position;
	Possible_Move possible_move;
	///////////////////////////////////////
	vector< vector<ChessPiece*> > Board = ChessBoard::GetBoard();
	vector<Possible_Move> All_Possible_Positions;
	current_position = GetPosition();
	bool Current_White = GetWhite();
	////
	int dx[]={ 1,1,-1,-1,-2,2,-2, 2};
	int dy[]={-2,2,-2, 2, 1,1,-1,-1};
	////
	for(int i=0 ; i<8 ; i++)
	{
		int x=current_position.x+dx[i];
		int y=current_position.y+dy[i];
		if(x>=0 && x<8 && y>=0 && y<8)
		{
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
			}
		}
	}
	return All_Possible_Positions;
}
void Knight::Draw(RenderWindow &window)
{
	Texture texture;
	Sprite sprite;
	if(this->GetWhite())
		texture.loadFromFile("Graphics\\KnightW.png");
	else
		texture.loadFromFile("Graphics\\KnightB.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->GetPosition().x * Board_Square_Width,this->GetPosition().y * Board_Square_Height);
	window.draw(sprite);
}