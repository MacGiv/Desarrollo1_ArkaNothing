#pragma once
#include "game_data.h"
#include "input_utils.h"

struct Paddle
{
    float posX;
    float posY;
    float speed;
    float sizeH;
    float sizeV;
    int lives;
    int score;
};


void movePaddleRight(Paddle& playerObj);

void movePaddleLeft(Paddle& playerObj);

void initializePaddle(Paddle& playerObj);

void updatePaddle(Paddle& playerObj, GameStateMachine& stateMachine);

void drawPaddle(Paddle& player);

void resetPaddlePos(Paddle& playerObj);

void checkLoseCondition(GameStateMachine& gameState, int playerLives);