#include "Game.h"

void Game::Start(void)
{
    VideoMode VMode(windowWidth, windowHeight, 32);
    RenderWindow Window(VMode, "Dodge");
    Window.setFramerateLimit(60);
    Window.setPosition(Vector2i(300,40));

    gameObject background("Images/black.png", 0, 0);
    
    player p("Images/playerBall.png", windowWidth/2, windowHeight/2);
    p.initPlayer();

    enemy e("Images/redBall.png", 10, 10);
    e.initEnemy();

    coin c("Images/coin.png", windowWidth/2, windowHeight/2);
    c.initCoin();

    Event event;
    while (Window.isOpen())
    {
        while (Window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                    Window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape)
                        Window.close();
                    break;
                default:
                    break;
            }
        }

        if(c.detectCollision(p.posRect))
        {
            c.updateCoinPos();
            e.increaseSpeed();
        }

        if(c.detectCollision(e.posRect))
        {
            c.updateCoinPos();
            e.decreaseSpeed();
        }

        if(p.detectCollision(e.posRect))
            p.resetPos();

        p.updatePlayerPos();
        e.updateEnemyPos();

        background.showGameObject(Window);
        p.showGameObject(Window);
        e.showGameObject(Window);
        c.showGameObject(Window);

        Window.display();
    }
}
