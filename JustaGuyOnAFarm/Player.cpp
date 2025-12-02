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
	float speed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) ? 6.f : 3.f;
	float diagonalSpeed = speed * 1.f;

	float dx = 0.f;
	float dy = 0.f;	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) dy -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) dy += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) dx -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) dx += speed;

	if (dx != 0.f && dy != 0.f) {
		float length = std::sqrt(dx * dx + dy * dy);
		dx = (dx / length) * diagonalSpeed;
		dy = (dy / length) * diagonalSpeed;
	}
	positionX += dx;
	positionY += dy;
	playerShape.setPosition({ positionX, positionY });
	playerCenterX = positionX + playerShape.getSize().x / 2;
	playerCenterY = positionY + playerShape.getSize().y / 2;
}
//player collison with the border
void Player::borderCollision(float windowSizeX, float WindowsizeY, float playerSizeX, float playerSizeY)
{
	
	if (positionX <= 0)
	{
		positionX = 0;
	}
	if (positionX > windowSizeX - playerSizeX)
	{

		positionX = windowSizeX - playerSizeX; //500 - 32
	}
	if (positionY <= 0)
	{
		positionY = 0;
	}
	if (positionY >= WindowsizeY - playerSizeY)
	{
		positionY = WindowsizeY - playerSizeY;
	}
}
//vytvoreni hrace
void Player::playerCreation(float posX, float posY, sf::Texture& TextureOfPlayer)
{
	positionX = posX;
	positionY = posY;
	playerShape.setSize(sf::Vector2f (TextureOfPlayer.getSize().x / 4, TextureOfPlayer.getSize().y / 4));
	playerShape.setPosition({ positionX, positionY });
	playerCenterX = positionX + (playerShape.getSize().x)/2;
	playerCenterY = positionY + (playerShape.getSize().y) / 2;
	health = 100;
	playerSizeX = playerShape.getSize().x;
	playerSizeY = playerShape.getSize().y;

	
	playerInnerHitbox.setOutlineColor(sf::Color::Black);
	playerInnerHitbox.setOutlineThickness(1);
	
	playerInnerHitbox.setSize(sf::Vector2f(playerSizeX / 4, playerSizeX / 4));
	
	playerOuterHitbox.setSize(sf::Vector2f(playerSizeX / 2, playerSizeY / 2));
	playerOuterHitbox.setOutlineColor(sf::Color::Red);
	playerOuterHitbox.setOutlineThickness(1);

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
bool Player::reachingVerticalPlaceForMapChange(float TransitionPointX, float lowerTransitionPointY, float higherTransitionPointY, float mapSizeX, float mapSizeY)
{
	int side = 0;
	if (TransitionPointX == 0) {
		side = 0;
	}
	else
		side = 1;

	switch (side) {
	case 0:
		if (!(positionX <= TransitionPointX)) return false;
		else {
			if (positionY > lowerTransitionPointY && positionY < higherTransitionPointY)
			{
				positionX = mapSizeX - 145; return true;

			}
		}
		return false;
		break;
	case 1:
		if (!(positionX >= TransitionPointX)) return false;
		else {
			if (positionY > lowerTransitionPointY && positionY < higherTransitionPointY)
			{
				positionX = 10; return true;
			}
			return false;
		}
		break;
	}


}
bool Player::reachingHorizontalPlaceForMapChange(float TransitionPointY, float lowerTransitionPointX, float higherTransitionPointX, float mapSizeX, float mapSizeY)
{
	int side = 0;
	if (TransitionPointY == 0) {
		side = 0;
	}
	else
		side = 1;

	switch (side) {
	case 0:
		if (!(positionY <= TransitionPointY)) return false;
		else {
			if (positionX > lowerTransitionPointX && positionX < higherTransitionPointX)
			{
				positionY = mapSizeY - 145; return true;

			}
		}
		return false;
		break;
	case 1:
		if (!(positionY >= TransitionPointY)) return false;
		else {
			if (positionX > lowerTransitionPointX && positionX < higherTransitionPointX)
			{
				positionY = 10; return true;
			}
			return false;
		}
		break;
	}


}
void Player::playerInnerHitboxUpdate()
{
	playerInnerHitbox.setPosition(sf::Vector2f(playerCenterX - ((playerSizeX / 4) / 2), playerCenterY - ((playerSizeY / 4) / 2)));
	playerOuterHitbox.setPosition(sf::Vector2f(playerCenterX - (playerSizeX / 4), playerCenterY - (playerSizeY / 4)));
}
