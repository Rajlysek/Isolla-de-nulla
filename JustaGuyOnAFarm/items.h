#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
class item
{
public:
	float positionX;
	float positionY;
	float sizeX;
	float sizeY;
	void itemCreation(sf::RectangleShape& itemShape, sf::Vector2f size, sf::Vector2f position);
	void itemPickup(sf::RectangleShape& item, sf::RectangleShape& PlayerOuterHitbox);
	void positionXCreation(int screenSizeX);	
	void positionYCreation(int screenSizeY);

};

