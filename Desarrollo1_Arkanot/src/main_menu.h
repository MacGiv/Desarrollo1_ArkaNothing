#pragma once
#include "game_data.h"
#include "input_utils.h"

void initializeMenu(char font);

void updateMenu(GameStateMachine& stateMachine);

void updateCredits(GameStateMachine& stateMachine);

void drawMenu();

void drawCredits();