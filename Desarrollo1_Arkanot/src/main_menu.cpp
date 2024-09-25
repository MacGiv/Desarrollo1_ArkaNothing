#include "main_menu.h"
#include "sl.h"

char menuFont;

void initializeMenu(char font)
{
	menuFont = font;
}

void updateMenu(GameStateMachine& stateMachine)
{
	if (isKeyPressed(SL_KEY_ENTER))
	{
		stateMachine.nextState = GAME_STATES::RUNNING;
	}
	else if (isKeyPressed('C'))
	{
		stateMachine.nextState = GAME_STATES::CREDITS;
	}
	else if (isKeyPressed(SL_KEY_BACKSPACE))
	{
		stateMachine.nextState = GAME_STATES::EXIT;
	}

}

void updateCredits(GameStateMachine& stateMachine)
{
	if (isKeyPressed(SL_KEY_BACKSPACE))
	{
		stateMachine.nextState = GAME_STATES::MENU;
	}
}

void drawMenu()
{
	slSetBackColor(0.0, 0.0, 0.0);
	int screenHeightPortion = screenHeight / 7;
	slSetFont(menuFont, fontSizeMedium);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slSetTextAlign(SL_ALIGN_CENTER);

	slSetFont(menuFont, fontSizeXL);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slText(screenWidth / 2, screenHeightPortion * 6, "ArkaNOT");

	slSetFontSize(fontSizeMedium);
	slText(screenWidth / 2, screenHeightPortion * 5, "Press:");
	slText(screenWidth / 2, screenHeightPortion * 4, "(ENTER) To play");
	slText(screenWidth / 2, screenHeightPortion * 3, "(C) To see credits");
	slText(screenWidth / 2, screenHeightPortion * 2, "(BACKSPACE/ESCAPE) To exit");
}

void drawCredits()
{
	int screenHeightPortion = screenHeight / 7;
	slSetFont(menuFont, fontSizeXL);
	slSetBackColor(0.0, 0.0, 0.0);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slSetTextAlign(SL_ALIGN_CENTER);
	slText(screenWidth / 2, screenHeightPortion*6, "ArkaNOT");

	slSetFontSize(fontSizeMedium);
	slText(screenWidth / 2, screenHeightPortion*5, "Tomas Francisco Luchelli");
	slText(screenWidth / 2, screenHeightPortion*4, "Practica Profesional I:");
	slText(screenWidth / 2, screenHeightPortion*3, "Desarrollo de Videojuegos I");
	slText(screenWidth / 2, screenHeightPortion*2, "Image Campus");
	slSetFontSize(fontSizeSmall);
	slText(screenWidth / 2, screenHeightPortion, "Press BACKSPACE to go back to Menu");
}