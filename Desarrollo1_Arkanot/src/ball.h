#pragma once
#include "game_data.h"

struct Ball
{
    float posX;
    float posY;
    float speedX;
    float speedY;
    float radius;
};

// Funciones para la bola
void initializeBall(Ball& ballObj);
void updateBall(Ball& ballObj);
void drawBall(const Ball& ballObj);
void checkBallCollisionWithWalls(Ball& ballObj);