#include <SFML/Graphics.hpp>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace sf;
using namespace std;

#ifndef ENEMY_H
#define ENEMY_H

#include "gameObject.h"

class enemy: public gameObject
{
    protected:
        Clock clock;
        int speed;
        float angle, elapsedTime, moveAmount;
    public:
        FloatRect posRect;
        enemy(string objFile, int x, int y): gameObject(objFile, x, y){};
        void initEnemy(void);
        void updateEnemyPos(void);
        void detectScreenCollision(void);
        void increaseSpeed(void);
        void decreaseSpeed(void);
};

#endif
