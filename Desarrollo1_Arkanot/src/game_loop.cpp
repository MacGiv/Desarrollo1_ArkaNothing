#include "game_loop.h"


GameStateMachine gameState;

Paddle player;

Ball ball;

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
    // Set up window 
    slWindow(screenWidth, screenHeight, "ArkaNOT", false);

    initializePaddle(player);

    initializeBall(ball);
}

void update()
{
    updatePaddle(player);

    updateBall(ball, player);
}

void draw()
{
    // Foreground color
    slSetForeColor(1.0, 1.0, 1.0, 1.0);

    drawPaddle(player);

    drawBall(ball);

    //Debug start
    slSetForeColor(1.0, 0.0, 0.0, 1.0);
    slCircleFill(player.posX, player.posY, 5.0, 20);
    slCircleFill(ball.posX, ball.posY, 5.0, 20);
    slSetForeColor(1.0, 1.0, 1.0, 1.0);
    //Debug end
    


    slRender();
}

void close()
{
    slClose();
}