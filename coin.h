#include <SFML/Graphics.hpp>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "mtrand/mtrand.h"
using namespace sf;
using namespace std;

#ifndef COIN_H
#define COIN_H

#include "gameObject.h"

class coin: public gameObject
{
    protected:
        MTRand_int32 irand;
        unsigned long s;
    public:
        FloatRect posRect;
        coin(string objFile, int x, int y): gameObject(objFile, x, y){};
        void initCoin(void);
        int detectCollision(FloatRect objRect);
        void updateCoinPos(void);
};

#endif
