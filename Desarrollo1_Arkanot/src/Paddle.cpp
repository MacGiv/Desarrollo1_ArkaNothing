#include "paddle.h"

void movePaddleRight(Paddle& playerObj)
{
	if (playerObj.posX > 0)
	{
		playerObj.posX -= playerObj.speed * slGetDeltaTime();
	}

}

void initializePlayer(Paddle& playerObj)
{
	playerObj.posX = playerStartPosX;
	playerObj.posY = playerStartPosY;
	playerObj.sizeH = playerStartWidth;
	playerObj.sizeV = playerHeight;
	playerObj.speed = playerStartSpeed;
	playerObj.score = 0;
}

void upldatePaddle()
{
	// if got input, update paddle pos
}

void getInput(bool& gotInput)
{
	

}

void upldatePaddlePos()
{

}