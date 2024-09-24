#include "game_loop.h"
#include "game_data.h"

GameStateMachine gameState;

Paddle player;

void runGame()
{
    initialize();
    
    while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
    {
        update();

        draw();
    }
    
    close();
}

void initialize()
{
    //Set up window 
    slWindow(screenWidth, screenHeight, "ArkaNOT", false);

    initializePlayer(player);
}

void update()
{
    updatePaddle(player);
}

void draw()
{
    // Foreground color
    slSetForeColor(1.0, 1.0, 1.0, 1.0);


    slRectangleFill(player.posX, player.posY, player.sizeH, player.sizeV);


    slRender();
}

void close()
{
    slClose();
}