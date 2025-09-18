#pragma once
#include <iostream>
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
class view
{
public:
		float positionX;
		float positionY;
		sf::View viewShape;
		void update(float x, float y);
};

