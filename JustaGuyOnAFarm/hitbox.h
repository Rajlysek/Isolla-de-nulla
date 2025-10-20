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
	void OuterHitboxCreation(float posX, float posY, float sizX, float sizY);
	void hitboxUpdate(float posX, float posY);
	bool isColliding(const hitbox& other);
	void OuterHitboxCreation();
	bool itemPickuping(sf::RectangleShape& item, sf::RectangleShape& PlayerOuterHitbox);
};

