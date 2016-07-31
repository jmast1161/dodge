#include "coin.h"

void coin::initCoin(void)
{
    s = 89UL;
    srand(time(NULL));
    s -= rand();
    irand.seed(s);
    xPos = abs((int)irand()%1024);
    yPos = abs((int)irand()%768);

    posRect = FloatRect(xPos, yPos, sprite.getLocalBounds().width, sprite.getLocalBounds().height);

    if(xPos + posRect.width > 1024)
        xPos -= posRect.width;
    if(yPos + posRect.height > 768)
        yPos -= posRect.height;
    posRect = FloatRect(xPos, yPos, posRect.width, posRect.height);
    sprite.setPosition(xPos, yPos);
}

int coin::detectCollision(FloatRect objRect)
{
    if(posRect.intersects(objRect))
        return 1;
    return 0;
}

void coin::updateCoinPos(void)
{
    xPos = abs((int)irand()%1024);
    yPos = abs((int)irand()%768);
    if(xPos + posRect.width > 1024)
        xPos -= posRect.width;
    if(yPos + posRect.height > 768)
        yPos -= posRect.height;
    posRect = FloatRect(xPos, yPos, posRect.width, posRect.height);
    sprite.setPosition(xPos, yPos);
}
