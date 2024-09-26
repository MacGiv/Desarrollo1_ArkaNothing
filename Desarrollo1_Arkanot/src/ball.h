#pragma once
#include "game_data.h"
#include "paddle.h"

struct Ball
{
    float posX;
    float posY;
    float speedX;
    float speedY;
    float radius;
};

void initializeBall(Ball& ballObj);

void updateBall(Ball& ballObj, Paddle& playerObj);

void drawBall(Ball& ballObj);

void checkBallCollisionWithWalls(Ball& ballObj, Paddle& player, bool& reset);

void ballPaddleCollisionCheck(Ball& ballObj, Paddle player);

void resetBall(Ball& ballObj);

