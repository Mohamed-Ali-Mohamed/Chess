#ifndef CHESSGAME_H
#define CHESSGAME_H
#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
////
#include<iostream>
#include<string>
#include<vector>
/////////
#include"GLOBALS.h"
#include"ChessBoard.h"
#include"King.h"
#include"Bishop.h"
#include"Pawn.h"
#include"Knight.h"
#include"Queen.h"
#include"Rook.h"
/////
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1100, 600), "Chess");
vector< vector<ChessPiece*> > Board;
struct Light
{
	ChessPiecePosition p;
	string choose;
}HL;
vector<Light> HightLight,Other;
ChessBoard* Initialize()
{
	ChessBoard* MyBoard=new ChessBoard();
	Other.clear();
	HightLight.clear();
	Board=MyBoard->GetBoard();
	return MyBoard;
}
void AddHightLight(RenderWindow &window)
{
	for(int i=0 ; i<HightLight.size() ; i++)
	{
		Texture texture;
		Sprite sprite;
		if(HightLight[i].choose =="Selected")
			texture.loadFromFile("Graphics\\selectedSquare.png");
		else if(HightLight[i].choose =="Move" || HightLight[i].choose =="Move&Change")
			texture.loadFromFile("Graphics\\AvailableDestination.png");
		else if(HightLight[i].choose =="Attack" || HightLight[i].choose =="Attack&Change")
			texture.loadFromFile("Graphics\\inThreat.png");
		sprite.setTexture(texture);
		sprite.setPosition(HightLight[i].p.x * Board_Square_Width,HightLight[i].p.y * Board_Square_Height);
		window.draw(sprite);
	}
}
void addOther(RenderWindow &window,bool White)
{
	for(int i=0 ; i<Other.size() ; i++)
	{
		Texture texture;
		Sprite sprite;
		if(Other[i].choose =="Move&Change" || Other[i].choose =="Attack&Change")
		{
			if(White)
				texture.loadFromFile("Graphics\\PromotionW.png");
			else
				texture.loadFromFile("Graphics\\PromotionB.png");
		}
		sprite.setTexture(texture);
		sprite.setPosition(Other[i].p.x ,Other[i].p.y );
		window.draw(sprite);
	}
}
void draw_board(bool White)
{
	window.clear(sf::Color::White);
	Texture texture;
	Sprite sprite;
	Font font;
	Text text;
	font.loadFromFile("Graphics\\ARIBL0.TTF");
	texture.loadFromFile("Graphics\\Chess_Board.png");
	sprite.setTexture(texture);
	text.setFont(font);
	if(White)text.setString("White Turn");
	else text.setString("Black Turn");
	text.setColor(sf::Color::Red);
	text.setCharacterSize(25);
	text.setPosition(Board_Square_Width*9, Board_Square_Height);
	window.draw(sprite);
	window.draw(text);

	AddHightLight(window);
	addOther(window,White);
	for(int y=0 ; y<8 ; y++)
	{
		for(int x=0 ; x<8 ; x++)
		{
			Board[y][x]->Draw(window);
		}
	}
	HightLight.clear();
	window.display();
}
void GetMouseClick(ChessPiecePosition &Input,string &Mouse_Action)
{
	Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return;
			}
		}
		//===============================================
		if(event.mouseButton.x>0 && event.mouseButton.x<597 && event.mouseButton.y>0 && event.mouseButton.y<597)
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Mouse_Action="Left";
				Input.x = event.mouseButton.x;
				Input.y = event.mouseButton.y;
				return ;
			}
			else if (Mouse::isButtonPressed(Mouse::Right))
			{
				Mouse_Action="Right";
				Input.x = event.mouseButton.x;
				Input.y = event.mouseButton.y;
				return ;
			}
		}
		if(Mouse_Action=="Change")
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Mouse_Action="Left";
				Input.x = event.mouseButton.x;
				Input.y = event.mouseButton.y;
				return ;
			}
		}
	}
}
void play(bool White,ChessBoard* MyBoard)
{
	string Action_Move="Move",Action_Attack="Attack",Action_MoveAndChange="Move&Change",Action_AttackAndChange="Attack&Change",Mouse_Action="";

	bool End=false;
	while (!End && window.isOpen())
	{
		draw_board(White);
		ChessPiecePosition From,To;
		From.x=From.y=To.x=To.y=-1;
		//Get From_X & From_Y by mouse
		GetMouseClick(From,Mouse_Action);
		if(!window.isOpen())break;
		if(Mouse_Action=="Right" || (From.x==-1 && From.y==-1))continue;
		From.y/=Board_Square_Height;From.x/=Board_Square_Width;
		if(Board[From.y][From.x]->GetWhite() != White)continue;
		////
		HL.p=From;
		HL.choose="Selected";
		HightLight.push_back(HL);
		////
		vector<Possible_Move> All = Board[From.y][From.x]->move();
		for(int i=0 ; i<All.size() ; i++)
		{
			HL.p=All[i].position;
			HL.choose=All[i].Action;
			HightLight.push_back(HL);
		}
		draw_board(White);
		////
		//Get To_X & To_Y by mouse
		GetMouseClick(To,Mouse_Action);
		if(!window.isOpen())break;
		if(To.x==-1 && To.y==-1 || Mouse_Action=="Right")
			continue;
		To.x/=Board_Square_Width;To.y/=Board_Square_Height;

		for(int i=0 ; i<All.size() ; i++)
		{
			if(All[i].position.x == To.x  &&  All[i].position.y == To.y)
			{
				if( (All[i].Action == Action_Attack || All[i].Action==Action_AttackAndChange) && Board[To.y][To.x]->GetName() == "King")
				{
					End=true;
				}
				Board[From.y][From.x]->SetPosition(To);
				Board[To.y][To.x]=Board[From.y][From.x];
				//
				ChessPiece* p =new ChessPiece();
				p->SetPosition(From);
				//
				Board[From.y][From.x]=p;
				//
				if(All[i].Action == Action_AttackAndChange || All[i].Action==Action_MoveAndChange)
				{
					HL.choose=All[i].Action;
					ChessPiecePosition p;
					p.x=Board_Square_Width*8;
					p.y=Board_Square_Height*3;
					HL.p=p;
					Other.push_back(HL);
					draw_board(White);
					/////////////////
					do
					{
						From.x=From.y=-1;
						//Get From_X & From_Y by mouse
						Mouse_Action="Change";
						GetMouseClick(From,Mouse_Action);
						if(!window.isOpen())break;
						if(Mouse_Action=="Right" || (From.x==-1 && From.y==-1))continue;
						From.y-=p.y;From.x-=p.x;
						/////////////////
					}while(From.y<85 || From.y>135 || From.x<5 || From.x>175);
					int c=From.x/45;
					if(c==0)
					{
						Queen* queen = new Queen();
						queen->SetWhite(White);
						queen->SetName("Queen");
						queen->SetPosition(To);
						Board[To.y][To.x]=queen;
					}
					else if(c==1)
					{
						Rook* rook = new Rook();
						rook->SetWhite(White);
						rook->SetName("Rook");
						rook->SetPosition(To);
						Board[To.y][To.x]=rook;
					}
					else if(c==2)
					{
						Knight* knight = new Knight();
						knight->SetWhite(White);
						knight->SetName("Knight");
						knight->SetPosition(To);
						Board[To.y][To.x]=knight;
					}
					else if(c==3)
					{
						Bishop* bishop = new Bishop();
						bishop->SetWhite(White);
						bishop->SetName("Bishop");
						bishop->SetPosition(To);
						Board[To.y][To.x]=bishop;
					}
					//
					Other.clear();
				}

				/////
				MyBoard->SetBoard(Board);
				/////
				White=!White;
				break;
			}
		}
	}
}
#endif