#include "player.h"

void player::initPlayer(void)
{
    speed = 500;
    elapsedTime = (float) clock.getElapsedTime().asSeconds();
    posRect = FloatRect(xPos, yPos, sprite.getLocalBounds().width, sprite.getLocalBounds().height);
}

void player::updatePlayerPos(void)
{
    elapsedTime = (float)clock.restart().asSeconds();
    getPlayerInput();
    posRect = FloatRect(xPos, yPos, sprite.getLocalBounds().width, sprite.getLocalBounds().height);
}

void player::getPlayerInput(void)
{
    if(Keyboard::isKeyPressed(Keyboard::Left))
        movePlayer(1, 0, 0, 0);
    else if(Keyboard::isKeyPressed(Keyboard::Right))
        movePlayer(0, 1, 0, 0);
    if(Keyboard::isKeyPressed(Keyboard::Up))
        movePlayer(0, 0, 1, 0);
    else if(Keyboard::isKeyPressed(Keyboard::Down))
        movePlayer(0, 0, 0, 1);
}

void player::movePlayer(int left, int right, int up, int down)
{
    if(left && xPos >= 0)
    {
        moveAmount = elapsedTime * (float)speed;
        xPos -= moveAmount;
        sprite.setPosition(xPos, yPos);
    }
    else if(right && xPos + sprite.getLocalBounds().width <= 1024)
    {
        moveAmount = elapsedTime * (float)speed;
        xPos += moveAmount;
        sprite.setPosition(xPos, yPos);
    }
    
    if(up && yPos >= 0)
    {
        moveAmount = elapsedTime * (float)speed;
        yPos -= moveAmount;
        sprite.setPosition(xPos, yPos);
    }
    else if(down && yPos + sprite.getLocalBounds().height <= 768)
    {
        moveAmount = elapsedTime * (float)speed;
        yPos += moveAmount;
        sprite.setPosition(xPos, yPos);
    }
}

int player::detectCollision(FloatRect objRect)
{
    if(posRect.intersects(objRect))
        return 1;
    return 0;
}

void player::resetPos(void)
{
    xPos = 1024/2;
    yPos = 768/2;
    sprite.setPosition(xPos, yPos);
    posRect = FloatRect(xPos, yPos, posRect.width, posRect. height);
}
