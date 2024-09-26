#include "ball.h"
#include "sl.h"  


void initializeBall(Ball& ballObj)
{
    ballObj.posX = playerStartPosX + (playerStartWidth / 2);
    ballObj.speedX = ballStartSpeedX;
    ballObj.speedY = ballStartSpeedY;
    ballObj.radius = ballStartRadius;
    ballObj.posY = playerStartPosY + paddleHeight + ballObj.radius;
}

void resetBall(Ball& ballObj)
{

}

void updateBall(Ball& ballObj, Paddle& playerObj)
{
    ballObj.posX += ballObj.speedX * slGetDeltaTime();
    ballObj.posY += ballObj.speedY * slGetDeltaTime();

    checkBallCollisionWithWalls(ballObj);
    ballPaddleCollisionCheck(ballObj, playerObj);
}

void drawBall(Ball& ballObj)
{
    slCircleFill(ballObj.posX, ballObj.posY, ballObj.radius, 20.0);
}

void checkBallCollisionWithWalls(Ball& ballObj, Paddle& player, bool& reset)
{
    // Left and right wall collision
    if (ballObj.posX - ballObj.radius <= 0 || ballObj.posX + ballObj.radius >= screenWidth)
    {
        ballObj.speedX *= -1;
        //Left collision
        if (ballObj.posX - ballObj.radius <= 0)
        {
            ballObj.posX = 0 + ballObj.radius;
        }
        //Right collision
        else
        {
            ballObj.posX = screenWidth - ballObj.radius;
        }
    }

    // Top wall collision
    if (ballObj.posY + ballObj.radius >= screenHeight)
    {
        ballObj.speedY *= -1;
        ballObj.posY = screenHeight - ballObj.radius;
    }

    // Bottom collision
    if (ballObj.posY - ballObj.radius <= 0)
    {
        player.lives--;
        reset = true;
    }
}

void ballPaddleCollisionCheck(Ball& ballObj, Paddle player)
{
    // Paddle limits
    float paddleLeft = player.posX - player.sizeH / 2;
    float paddleRight = player.posX + player.sizeH / 2;
    float paddleTop = player.posY + player.sizeV / 2;
    float paddleBottom = player.posY - player.sizeV / 2;

    // Ball limits
    float ballLeft = ballObj.posX - ballObj.radius;
    float ballRight = ballObj.posX + ballObj.radius;
    float ballTop = ballObj.posY + ballObj.radius;
    float ballBottom = ballObj.posY - ballObj.radius;

    // Check collisions
    if (ballRight >= paddleLeft && ballLeft <= paddleRight &&
        ballBottom <= paddleTop && ballTop >= paddleBottom)
    {
        // Get the amount of overlapping in each collision
        float overlapLeft = ballRight - paddleLeft;
        float overlapRight = paddleRight - ballLeft;
        float overlapTop = ballTop - paddleBottom;
        float overlapBottom = paddleTop - ballBottom;

        // Get collision side
        bool collisionHorizontal = overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom ||
            overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom;

        bool collisionVertical = overlapTop < overlapBottom && overlapTop < overlapLeft && overlapTop < overlapRight ||
            overlapBottom < overlapTop && overlapBottom < overlapLeft && overlapBottom < overlapRight;

        if (collisionHorizontal)
        {
            ballObj.speedX *= -1;

            // Right collision
            if (overlapLeft < overlapRight)
            {
                // Ball relocated to avoid getting stuck in the paddle. 
                ballObj.posX = paddleLeft - ballObj.radius - ballPaddleSafeDistance;
            }
            // Left collision
            else
            {
                ballObj.posX = paddleRight + ballObj.radius + ballPaddleSafeDistance;
            }
        }
        else if (collisionVertical)
        {
            ballObj.speedY *= -1;
            // Top collision
            if (ballObj.speedY > 0)
            {
                ballObj.posY = paddleTop + ballObj.radius + ballPaddleSafeDistance;
            }
        }
    }
}