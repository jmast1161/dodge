#include "enemy.h"

void enemy::initEnemy(void)
{
    elapsedTime = (float) clock.getElapsedTime().asSeconds();
    speed = 500;
    posRect = FloatRect(xPos, yPos, sprite.getLocalBounds().width, sprite.getLocalBounds().height);
    srand(time(NULL));
    angle = (float) (rand() % 360);
    if(angle < 10 || (angle > 80 && angle < 100) || (angle > 170 && angle < 190) || (angle > 260 && angle < 280) || angle > 350)
        angle += 30;
}

void enemy::updateEnemyPos(void)
{
    elapsedTime = (float)clock.restart().asSeconds();
    moveAmount = elapsedTime * speed;
    xPos += (int)(cos((angle - 90) * 3.14159f / 180.0f) * moveAmount);
    yPos += (int)(sin((angle - 90) * 3.14158f / 180.0f) * moveAmount);
    sprite.setPosition(xPos, yPos);
    detectScreenCollision();
    posRect = FloatRect(xPos, yPos, posRect.width, posRect.height);
}

void enemy::detectScreenCollision(void)
{
    if(xPos <= 0)
    {
        angle = 360.0 - angle;
        xPos += 2; //add 2 so ball does not get stuck on wall
    }
    else if(xPos + posRect.width >= 1024)
    {
        angle = 360.0 - angle;
        xPos -= 2;
    }

    if(yPos < 0)
    {
        angle = 180.0 - angle;
        yPos += 2;  //add 2 so ball does not get stuck on wall
    }
    else if(yPos + posRect.height >= 768)
    {
        angle = 180.0 - angle;
        yPos -= 2;
    }
}

void enemy::increaseSpeed(void)
{
    speed += 20;
}

void enemy::decreaseSpeed(void)
{
    speed -= 20;
}
