#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
class hitbox
{
public:
	float positionX;
	float positionY;
	float sizeX;
	float sizeY;
	sf::RectangleShape hitboxShape;
	void hitboxCreation(float posX, float posY, float sizX, float sizY);
	void hitboxUpdate(float posX, float posY);
	bool isColliding(const hitbox& other);
};

