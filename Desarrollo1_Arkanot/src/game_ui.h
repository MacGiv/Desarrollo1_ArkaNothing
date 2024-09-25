#pragma once
#include "sl.h"
#include "game_data.h"
 

void initializeUi(char font);

void updateScore(int playerScore);

void drawScore(int playerScore);

void updatePlayerLives(int playerLives);

void drawLivesUi(int playerLives);

void drawGameOver();