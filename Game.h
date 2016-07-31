#pragma once
#define windowWidth 1024
#define windowHeight 768
#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "gameObject.h"
#include "player.h"
#include "enemy.h"
#include "coin.h"
using namespace std;
using namespace sf;

class Game
{
    public:
        static void Start(void);
};
