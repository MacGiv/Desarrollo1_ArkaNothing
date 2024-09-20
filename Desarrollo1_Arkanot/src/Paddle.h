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

void movePaddleRight(Paddle& player);