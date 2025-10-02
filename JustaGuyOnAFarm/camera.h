#pragma once
#include <iostream>
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
class camera
{
public:
	void update(float playerPosX, float playerPosY, sf::View& view);
	void borderCollisionView(float playerPosX, float playerPosY, unsigned int screenSizeX, unsigned int screenSizeY, float backgroundWidth, float backgroundHeight, sf::View& view);
};

