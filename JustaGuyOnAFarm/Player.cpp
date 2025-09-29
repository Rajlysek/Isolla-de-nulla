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
			float x = 0.75;
			positionX += x;
			float y = -0.65;
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
			float x = -0.75;
			positionX += x;
			float y = -0.65;
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
			float x = 0.75;
			positionX += x;
			float y = 0.65;
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
			float x = -0.75;
			positionX += x;
			float y = 0.65;
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
void Player::borderCollision(float windowSizeX, float WindowsizeY, float playerSizeX, float playerSizeY)
{
	
	if (positionX <= 0)
	{
		positionX = 0;
	}
	if (positionX > windowSizeX - playerSizeX*3)
	{

		positionX = windowSizeX - playerSizeX*3; //500 - 32
	}
	if (positionY <= 0)
	{
		positionY = 0;
	}
	if (positionY >= WindowsizeY - playerSizeY*3)
	{
		positionY = WindowsizeY - playerSizeY*3;
	}
}

void Player::playerCreation(float posX, float posY)
{
	positionX = posX / 2;
	positionY = posY / 2;
	playerShape.setSize({ 32.f, 32.f });
	playerShape.setPosition({ positionX, positionY });
	health = 100;
}
void Player::positionChange(float x, float y) {
	positionX = x;
	positionY = y;
	playerShape.setPosition({ x,y });
}
