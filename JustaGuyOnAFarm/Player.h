#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
class Player
{
public:
	float positionX;
	float positionY;
	sf::RectangleShape playerShape;
	float playerSizeX;
	float playerSizeY;
	int health;
	void move();
	void borderCollision(int x, int y, float sizeX, float sizeY);
	void playerCreation(float posX, float posY);

};


