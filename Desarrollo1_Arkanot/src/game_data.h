#pragma once
#include "sl.h"

const int screenWidth = 800;
const int screenHeight = 450;

const float playerMargin = 20.0f;
const float playerStartWidth = 25.0f;
const float playerHeight = 100.0f;
const int playerOneStartPosX = 0 + playerMargin;
const int playerStartPosY = screenHeight / 2 - (playerHeight / 2);
const int playerTwoStartPosX = screenWidth - playerStartWidth - playerMargin;

const int fontSizeSmall = 25;
const int fontSizeMedium = 35;
const int fontSizeLarge = 50;
const int fontSizeXL = 80;

const double timeBeforeClosing = 2;
const double timeBeforeStart = 1;