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
	int positionX;
	int positionY;
	void update(float playerPosX, float playerPosY, sf::View& view);
	void borderCollisionView(float playerCenterX, float playerCenterY, float playerPosX, float playerPosY,  int screenSizeX,  int screenSizeY, float backgroundWidth, float backgroundHeight, sf::View& view);
};

