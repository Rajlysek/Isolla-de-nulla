#include "items.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

void item::itemCreation(sf::RectangleShape& itemShape, sf::Vector2f size, sf::Vector2f position)
{
	itemShape.setSize(size);
	itemShape.setPosition(position);
	itemShape.setFillColor(sf::Color::Black);
}
bool item::itemPickup(sf::RectangleShape& item, sf::RectangleShape& PlayerOuterHitbox)
{
	
	
	if (item.getGlobalBounds().findIntersection(PlayerOuterHitbox.getGlobalBounds()))			
	{
		std::cout << "Item picked up!" << std::endl;
		return true;
	}
	else {
		return false;
	}
}