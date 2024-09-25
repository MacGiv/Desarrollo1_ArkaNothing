#include "pause_menu.h"

char pause_font;

void initializePause(char font)
{
	pause_font = font;
}

void updatePause(GameStateMachine stateMachine)
{
	if (isKeyPressed(SL_KEY_ENTER))
	{
		stateMachine.nextState = GAME_STATES::RUNNING;
	}
	else if (isKeyPressed(SL_KEY_BACKSPACE))
	{
		stateMachine.nextState = GAME_STATES::MENU;
	}
	else if (isKeyPressed(SL_KEY_ESCAPE))
	{
		stateMachine.nextState = GAME_STATES::EXIT;
	}

}

void drawPause()
{
	slSetBackColor(0.0, 0.0, 0.0);
	int screenHeightPortion = screenHeight / 7;
	slSetFont(pause_font, fontSizeMedium);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slSetTextAlign(SL_ALIGN_CENTER);

	slSetFont(pause_font, fontSizeXL);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slText(screenWidth / 2, screenHeightPortion * 6, "Pause");

	slSetFontSize(fontSizeMedium);
	slText(screenWidth / 2, screenHeightPortion * 4, "Press (ENTER) to continue");
	slText(screenWidth / 2, screenHeightPortion * 2, "Press (ESCAPE) To exit");
	slSetFontSize(fontSizeSmall);
	slText(screenWidth / 2, screenHeightPortion, "Press BACKSPACE to go back to Menu");
}
