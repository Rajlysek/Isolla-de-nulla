#include "items.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <stdlib.h>     

void item::itemCreation(sf::RectangleShape& itemShape, sf::Vector2f size, sf::Vector2f position)
{
	itemShape.setSize(size);
	itemShape.setPosition(position);
	itemShape.setFillColor(sf::Color::Black);
	isVisible = true;
}
void item::checkingItemVisibility()
{
	if (isVisible == false) 
	{
		body.setFillColor(sf::Color::Transparent);
	}
	else {
		body.setFillColor(sf::Color::Black);
	}
}
void item::itemPickup(sf::RectangleShape& PlayerOuterHitbox)
{
	
	if (isVisible){
		if (body.getGlobalBounds().findIntersection(PlayerOuterHitbox.getGlobalBounds()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			isVisible = false;
		}
	}
}
void item::positionXCreation(int screenSizeX){
	positionX = rand() % (screenSizeX - 30) + 1;
}

void item::positionYCreation(int screenSizeY) {

	positionY = rand() % (screenSizeY-30) + 1;
}



