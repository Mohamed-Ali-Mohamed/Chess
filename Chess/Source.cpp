#include"ChessGame.h"
int main()
{
	while (window.isOpen())
	{
		bool White=true;
		ChessBoard* MyBoard=Initialize();
		draw_board(White);
		play(White,MyBoard);
	}
	return 0;
}