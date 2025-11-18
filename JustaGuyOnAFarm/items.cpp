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
}
void item::itemPickup(sf::RectangleShape& item, sf::RectangleShape& PlayerOuterHitbox)
{
	
	
	if (item.getGlobalBounds().findIntersection(PlayerOuterHitbox.getGlobalBounds()))			
	{
		std::cout << "Item picked up!" << std::endl;
		item.setFillColor(sf::Color::Transparent);
	}
}
void item::positionXCreation(int screenSizeX){
	positionX = rand() % screenSizeX + 1;
}

void item::positionYCreation(int screenSizeY) {

	positionY = rand() % screenSizeY + 1;
}



