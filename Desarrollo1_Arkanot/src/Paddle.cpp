#include "paddle.h"



void movePaddleRight(Paddle& player)
{
	if (player.posX > 0)
	{
		player.posX -= player.speed * slGetDeltaTime();
	}

}