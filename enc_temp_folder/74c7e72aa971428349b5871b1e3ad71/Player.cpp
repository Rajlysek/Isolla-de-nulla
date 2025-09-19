#include "Player.h"
#include "Player.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float x = 4.f;
			positionX += x;
			float y = -4.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });

		}
		else {
			float x = 3.f;
			positionX += x;
			float y = -3.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float x = -4.f;
			positionX += x;
			float y = -4.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });

		}
		else {
			float x = -3.f;
			positionX += x;
			float y = -3.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float x = 4.f;
			positionX += x;
			float y = 4.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });

		}
		else {
			float x = 3.f;
			positionX += x;
			float y = 3.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float x = -4.f;
			positionX += x;
			float y = 4.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });

		}
		else {
			float x = -3.f;
			positionX += x;
			float y = 3.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float x = 0.f;
			positionX += x;
			float y = 0.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });

		}
		else {
			float x = 0.f;
			positionX += x;
			float y = 0.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });
		}
	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float y = -10.f;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });

		}
		else
		{
			float y = -6.f;
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
			float y = 6.f;
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
			float x = -6.f;
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
			float x = 6.f;
			positionX += x;
			playerShape.setPosition({ positionX, positionY });
		}
	}
	

}
void Player::borderCollision(int x, int y, float sizeX, float sizeY)
{
	if (positionX <= 0)
	{
		positionX = 0;
	}
	if (positionX >= sizeX - 50)
	{

		positionX = sizeX - 50;
	}
	if (positionY <= 0)
	{
		positionY = 0;
	}
	if (positionY >= sizeY - 50)
	{
		positionY =sizeY- 50;
	}
}

void Player::playerCreation(float posX, float posY)
{
	positionX = posX / 2;
	positionY = posY / 2;
	playerShape.setSize({ 50.f, 50.f });
	playerShape.setPosition({ positionX, positionY });
	health = 100;
}
