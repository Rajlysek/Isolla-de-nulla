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
	void move();
	void borderCollision(float x, float y);

};


