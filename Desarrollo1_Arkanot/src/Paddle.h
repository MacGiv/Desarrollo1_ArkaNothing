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
    int score;
};


void movePaddleRight(Paddle& playerObj);

void movePaddleLeft(Paddle& playerObj);

void initializePaddle(Paddle& playerObj);

void updatePaddle(Paddle& playerObj);

void drawPaddle(Paddle& player);

void resetPaddlePos();