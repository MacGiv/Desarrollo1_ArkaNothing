#include "game_ui.h"
#include "sl.h"
#include <string>
using namespace std;

char uiFont;
int currentScore = 0;
int currentLives = 0;

void initializeUi(char font)
{
	uiFont = font;
}

void updateScore(int playerScore)
{
	currentScore = playerScore;
}

void drawScore(int playerScore)
{
	int scorePosY = (screenHeight / 10) * 9.5f;
	
	slSetForeColor(1.0, 0.0, 0.0, 0.0);
	slSetTextAlign(SL_ALIGN_CENTER);
	slSetFont(uiFont, fontSizeMedium);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	string scoreText = "Score: " + to_string(playerScore);
	slText(screenWidth / 2,scorePosY , scoreText.c_str());

}

void updatePlayerLives(int playerLives)
{
	currentLives = playerLives;
}

void drawLivesUi(int playerLives)
{
	int livesPosY = (screenHeight / 10) * 9.5f;
	int livesPosX =screenWidth/4;

	slSetForeColor(1.0, 0.0, 0.0, 0.0);
	slSetTextAlign(SL_ALIGN_CENTER);
	slSetFont(uiFont, fontSizeMedium);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slText(screenWidth / 10, livesPosY, "Lives:");
	switch (playerLives)
	{
	case 1:
		slText(livesPosX, livesPosY, "X O O");
		break;
	case 2:
		slText(livesPosX, livesPosY, "X X O");
		break;
	case 3:
		slText(livesPosX, livesPosY, "X X X");
		break;
	default:
		slText(livesPosX, livesPosY, "X.X");
		break;
	}
}

void drawGameOver()
{
	int msgPosX = screenWidth / 2;
	int msgPosY = (screenHeight / 3) * 2;
	int msg2PosY = (screenHeight / 3);
	
	slSetForeColor(1.0, 0.0, 0.0, 0.0);
	slSetTextAlign(SL_ALIGN_CENTER);
	slSetFont(uiFont, fontSizeMedium);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slText(msgPosX, msgPosY, "Game Over!");
	slText(msgPosX, msg2PosY, "Thank you for playing!");
}

void updateGameOver()
{
	
}