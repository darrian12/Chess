#define OLC_PGE_APPLICATION

#include "Chess.h"

int main()
{	
	Chess game("Chess Game");
	if (game.Construct(440, 440, 2, 2, false, false))
		game.Start();

	return 0;
}