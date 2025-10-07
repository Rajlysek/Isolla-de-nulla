#include "Player.h"
#include "Player.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "map.h"
//long function that handles player movement and running with shift key and usage of pythagorean theorem for diagonal movement
void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float x = 1.4;
			positionX += x;
			float y = -1.4;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });

		}
		else {
			float x = 0.7;
			positionX += x;
			float y = -0.7;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float x = -1.4;
			positionX += x;
			float y = -1.4;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });

		}
		else {
			float x = -0.7;
			positionX += x;
			float y = -0.7;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float x = 1.4;
			positionX += x;
			float y = 1.4;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });

		}
		else {
			float x = 0.7;
			positionX += x;
			float y = 0.7;
			positionY += y;
			playerShape.setPosition({ positionX, positionY });
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
			float x = -1.4;
			positionX += x;
			float y = 1.4;
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
//player collison with the border
void Player::borderCollision(float windowSizeX, float WindowsizeY, float playerSizeX, float playerSizeY)
{
	
	if (positionX <= 0)
	{
		positionX = 0;
	}
	if (positionX > windowSizeX - playerSizeX*4.5)
	{

		positionX = windowSizeX - playerSizeX*4.5; //500 - 32
	}
	if (positionY <= 0)
	{
		positionY = 0;
	}
	if (positionY >= WindowsizeY - playerSizeY*4.5)
	{
		positionY = WindowsizeY - playerSizeY *4.5;
	}
}
//vytvoreni hrace
void Player::playerCreation(float posX, float posY)
{
	positionX = posX;
	positionY = posY;
	playerShape.setSize({ 32.f, 32.f });
	playerShape.setPosition({ positionX, positionY });
	health = 100;
}
void Player::positionChange(float x, float y) {
	positionX = x;
	positionY = y;
	playerShape.setPosition({ x,y });
}

//int Player::directionOfPlayer() {
//	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
//	{
//		return 2;
//	}
//	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//player texture change when moving left or right
void Player::changeDirectionTexture(sf::Texture& playerTexture, const std::filesystem::path& animationPicture)
{
		playerTexture.loadFromFile(animationPicture);

}
bool Player::reachingPlaceForMapChange(float lowerTransitionPointX, float higherTransitionPointX, float lowerTransitionPointY, float higherTransitionPointY, float mapSizeX, float mapSizeY)
{
	if(positionX >= lowerTransitionPointX && positionX <= higherTransitionPointX)
	{
		
		if (positionX <= mapSizeX / 2) {
			positionX = mapSizeX - playerSizeX * 4.5 - 10;
			return true;
		}
		else {
			positionX = 10;
			return true;
		}
	}
	else if (positionY >= lowerTransitionPointY && positionY <= higherTransitionPointY)
	{
		if (positionY <= mapSizeY / 2) {
			positionY = mapSizeY - playerSizeY * 4.5 - 10;
			return true;
		}
		else {
			positionY = 10;
			return true;
		}
	}
	else {
		return false;
	}
}