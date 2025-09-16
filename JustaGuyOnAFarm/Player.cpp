#include "Player.h"
#include "Player.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float y = -10.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });

		}
		else
		{
			float y = -5.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {

			float y = 10.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });
		}
		else {
			float y = 5.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
		{
			float x = -10.f;
			positionX += x;
			playerShape.setPosition({ positionX, positionY });

		}
		else {
			float x = -5.f;
			positionX += x;
			playerShape.setPosition({ positionX, positionY });
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float x = 10.f;
			positionX += x;
			playerShape.setPosition({ positionX, positionY });
		}
		else
		{
			float x = 5.f;
			positionX += x;
			playerShape.setPosition({ positionX, positionY });
		}
	}
}
void Player::borderCollision(float x, float y)
{
	if (positionX <= 0)
	{
		positionX = 0;
	}
	if (positionX >= x - 50)
	{

		positionX = x - 50;
	}
	if (positionY <= 0)
	{
		positionY = 0;
	}
	if (positionY >= y - 50)
	{
		positionY = y - 50;
	}
}
