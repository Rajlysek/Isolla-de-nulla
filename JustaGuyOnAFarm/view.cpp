#include <iostream>
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "view.h"
Player player;
void view::update(float x, float y)
{
	player.positionX = x;
	player.positionY = y;
	viewShape.setCenter({ positionX, positionY });
}	
