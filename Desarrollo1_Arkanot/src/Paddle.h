#pragma once
#include "game_data.h"

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

void initializePlayer(Paddle& playerObj);

void upldatePaddle();

void getInput(bool& gotInput);

void upldatePaddlePos();