#pragma once
#include "game_data.h"
#include "ball.h"
#include "paddle.h"

enum class GAME_STATES { NOT_STARTED, PAUSED, RUNNING, GAMEOVER, CREDITS };

struct GameStateMachine
{
	GAME_STATES currentState;
	GAME_STATES nextState;
};


void runGame();

void initialize();

void update();

void draw();

void close();