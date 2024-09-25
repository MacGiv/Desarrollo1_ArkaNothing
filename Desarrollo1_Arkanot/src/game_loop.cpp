#include "game_loop.h"

GameStateMachine gameState;
Paddle player;
Ball ball;
Brick bricks[bricksAmount];

bool exitGame = false;
bool stayInMenu = true;
bool keyWasPressed = false;

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
    slWindow(screenWidth, screenHeight, "ArkaNOT", false);

    char font = slLoadFont("res/hemi_head.otf");

    initializePaddle(player);

    initializeBall(ball);

    initializeBricks(bricks, bricksAmount);

    initializeMenu(font);

    initializePause(font);

    initializeUi(font);

    gameState.currentState = GAME_STATES::MENU;
    gameState.nextState = GAME_STATES::MENU;
}

void update()
{
    switch (gameState.currentState)
    {
    case GAME_STATES::MENU:
        updateMenu(gameState);
        break;
    case GAME_STATES::NOT_STARTED:
        
        break;
    case GAME_STATES::PAUSED:
        updatePause(gameState);
        break;
    case GAME_STATES::RUNNING:
        updatePaddle(player, gameState);

        updateBall(ball, player);

        updateBricks(ball, bricks, bricksAmount, player.score);

        updateScore(player.score);

        updatePlayerLives(player.lives);

        checkLoseCondition(gameState, player.lives);

        break;
    case GAME_STATES::GAMEOVER:

        break;
    case GAME_STATES::CREDITS:
        updateCredits(gameState);
        break;
    case GAME_STATES::EXIT:
        close();
        break;
    default:
        break;
    }
    
    gameState.currentState = gameState.nextState;
}

void draw()
{
    switch (gameState.currentState)
    {
    case GAME_STATES::MENU:
        drawMenu();
        break;
    case GAME_STATES::NOT_STARTED:

        break;
    case GAME_STATES::PAUSED:
        drawPause();
        break;
    case GAME_STATES::RUNNING:
        slSetForeColor(1.0, 1.0, 1.0, 1.0);
        drawPaddle(player);
        drawBall(ball);
        drawBricks(bricks, bricksAmount);
        drawLivesUi(player.lives);
        drawScore(player.score);
        break;
    case GAME_STATES::GAMEOVER:
        drawGameOver();
        break;
    case GAME_STATES::CREDITS:
        drawCredits();
        break;
    default:
        break;
    }

    slRender();
}

void close()
{
    slClose();
}