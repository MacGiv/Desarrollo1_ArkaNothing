#include "bricks.h"
#include "sl.h"

Brick createBrick(int posX, int posY, float width, float height)
{
    Brick auxBrick;
    auxBrick.posX = posX;
    auxBrick.posY = posY;
    auxBrick.width = width;
    auxBrick.height = height;
    auxBrick.isDestroyed = false;
    return auxBrick;
}


void initializeBricks(Brick bricks[], int totalBricks)
{
    // Valores fijos para los ladrillos
    float brickWidth = 60.0f;
    float brickHeight = 30.0f;
    float startX = 50.0f;  // Posición de inicio en X
    float startY = screenHeight - (screenHeight * 0.10f);
    float horizontalSpacing = 10.0f;
    float verticalSpacing = 10.0f;

    // Calculamos la cantidad de columnas en función del ancho de la pantalla y los ladrillos
    int cols = (screenWidth - startX * 2) / (brickWidth + horizontalSpacing);
    int rows = (totalBricks + cols - 1) / cols;  // Calculamos las filas necesarias

    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= cols && index < totalBricks; j++)
        {
            float posX = startX + j * (brickWidth + horizontalSpacing);
            float posY = startY - i * (brickHeight + verticalSpacing);

            bricks[index] = createBrick(posX, posY, brickWidth, brickHeight);
            index++;
        }
    }
}

void drawBricks(Brick bricks[], int brickCount) 
{
    for (int i = 0; i < brickCount; i++) 
    {
        if (!bricks[i].isDestroyed) 
        {
            slRectangleFill(bricks[i].posX, bricks[i].posY, bricks[i].width, bricks[i].height);
        }
    }
}

void ballBrickCollisionCheck(Ball& ballObj, Brick& brick) 
{
    if (!brick.isDestroyed) 
    {
        // Brick limits
        float brickLeft = brick.posX - brick.width / 2;
        float brickRight = brick.posX + brick.width / 2;
        float brickTop = brick.posY + brick.height / 2;
        float brickBottom = brick.posY - brick.height / 2;

        // Ball limits
        float ballLeft = ballObj.posX - ballObj.radius;
        float ballRight = ballObj.posX + ballObj.radius;
        float ballTop = ballObj.posY + ballObj.radius;
        float ballBottom = ballObj.posY - ballObj.radius;

        // Check collisions
        if (ballRight >= brickLeft && ballLeft <= brickRight && 
            ballBottom <= brickTop && ballTop >= brickBottom)
        {
            brick.isDestroyed = true;

            float overlapLeft = ballRight - brickLeft;
            float overlapRight = brickRight - ballLeft;
            float overlapTop = ballTop - brickBottom;
            float overlapBottom = brickTop - ballBottom;

            bool collisionHorizontal = overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom ||
                overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom;

            bool collisionVertical = overlapTop < overlapBottom && overlapTop < overlapLeft && overlapTop < overlapRight ||
                overlapBottom < overlapTop && overlapBottom < overlapLeft && overlapBottom < overlapRight;

            // Ajustar dirección de la pelota según el lado de la colisión
            if (collisionHorizontal) 
            {
                ballObj.speedX *= -1;
            }
            if (collisionVertical) 
            {
                ballObj.speedY *= -1;
            }
        }
    }
}

void updateBricks(Ball& ballObj, Brick bricks[], int totalBricks)
{
    for (int i = 0; i < totalBricks; i++)
    {
        ballBrickCollisionCheck(ballObj, bricks[i]);
    }
}