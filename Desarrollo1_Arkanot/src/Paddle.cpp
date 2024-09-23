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
	if (isKeyDown(SL_KEY_SPACE, wasSpacePressed)) {
		std::cout << "Tecla SPACE presionada!" << std::endl;
	}

	if (isKeyUp(SL_KEY_SPACE, wasSpacePressed)) {
		std::cout << "Tecla SPACE soltada!" << std::endl;
	}

	if (isKeyPressed(SL_KEY_SPACE)) {
		std::cout << "Tecla SPACE mantenida" << std::endl;
	}
}

void getInput(bool& gotInput)
{
	

}

void upldatePaddlePos()
{

}