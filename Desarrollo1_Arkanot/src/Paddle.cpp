#include "paddle.h"
#include "sl.h"

void movePaddleRight(Paddle& playerObj)
{
	if (playerObj.posX < screenWidth - playerObj.sizeH / 2)
	{
		playerObj.posX += playerObj.speed * slGetDeltaTime();
	}
}

void movePaddleLeft(Paddle& playerObj)
{
	if (playerObj.posX > 0 + playerObj.sizeH / 2)
	{
		playerObj.posX -= playerObj.speed * slGetDeltaTime();
	}
}

void initializePaddle(Paddle& playerObj)
{
	playerObj.posX = playerStartPosX;
	playerObj.posY = playerStartPosY;
	playerObj.sizeH = playerStartWidth;
	playerObj.sizeV = playerHeight;
	playerObj.speed = playerStartSpeed;
	playerObj.score = 0;
}

void updatePaddle(Paddle& playerObj)
{
	if (isKeyPressed(SL_KEY_RIGHT)) 
	{
		movePaddleRight(playerObj);
	}

	if (isKeyPressed(SL_KEY_LEFT)) 
	{
		movePaddleLeft(playerObj);
	}
}

void drawPaddle(Paddle& player)
{
	slRectangleFill(player.posX, player.posY, player.sizeH, player.sizeV);
}


void resetPaddlePos()
{

}