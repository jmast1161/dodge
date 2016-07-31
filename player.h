#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h"

class player: public gameObject
{
    protected:
        Clock clock;
        int speed;
        float elapsedTime, moveAmount;
    public:
        FloatRect posRect;
        player(string objFile, int x, int y): gameObject(objFile, x, y){};
        void initPlayer(void);
        void updatePlayerPos(void);
        void getPlayerInput(void);
        void movePlayer(int left, int right, int up, int down);
        int detectCollision(FloatRect objRect);
        void resetPos(void);
};

#endif
