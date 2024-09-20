#pragma once

enum class GAME_STATES { NOT_STARTED, PAUSED, RUNNING, GAMEOVER, CREDITS };

struct GameStateMachine
{
	GAME_STATES currentState;
	GAME_STATES nextState;
};

GameStateMachine gameState;



