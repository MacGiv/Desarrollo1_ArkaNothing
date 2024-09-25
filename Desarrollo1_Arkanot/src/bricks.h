#pragma once
#include "ball.h"
#include "game_data.h"

struct Brick 
{
    float posX;
    float posY;
    float width;
    float height;
    bool isDestroyed;
};

Brick createBrick(int posX, int posY, float width, float height);

void initializeBricks(Brick bricks[], int totalBricks);

void drawBricks(Brick bricks[], int totalBricks);

void ballBrickCollisionCheck(Ball& ballObj, Brick& brick);

void updateBricks(Ball& ballObj, Brick bricks[], int totalBricks);