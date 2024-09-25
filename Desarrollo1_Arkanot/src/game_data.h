#pragma once

enum class GAME_STATES { MENU, NOT_STARTED, PAUSED, RUNNING, GAMEOVER, CREDITS, EXIT };

struct GameStateMachine
{
	GAME_STATES currentState;
	GAME_STATES nextState;
};

const int screenWidth = 1024;
const int screenHeight = 768;
const int topMargin = 15.0f;

const float ballStartSpeedX = 500.0f;
const float ballStartSpeedY = 400.0f;
const float ballStartRadius = 15.0f;
const float ballPaddleSafeDistance = 2.0f;

const int marginForUi = (screenHeight * 0.10f);

const int bricksAmount = 70;
const float brickWidth = 60.0f;
const float brickHeight = 30.0f;
const float brickStartPosX = 50.0f;
const float brickStartPosY = screenHeight - marginForUi;
const float brickHorizontalSpacing = 10.0f;
const float brickVerticalSpacing = 10.0f;

const float playerStartWidth = 125.0f;
const float playerHeight = 35.0f;
const float playerStartPosX = screenWidth / 2;
const float playerStartPosY = (screenHeight / 20);
const float playerStartSpeed = 450.0f;

const int fontSizeSmall = 35;
const int fontSizeMedium = 50;
const int fontSizeLarge = 80;
const int fontSizeXL = 110;

const int paddleHeight = 50;
const int paddleWidth = 150;

