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
	sf::RectangleShape playerInnerHitbox;
	sf::RectangleShape playerOuterHitbox;
	float playerSizeX;
	float playerSizeY;
	float playerCenterX;
	float playerCenterY;
	int health;
	void move();
	void borderCollision( float windowSizeX, float WindowsizeY, float playerSizeX, float playerSizeY);
	void playerCreation(float posX, float posY);
	void positionChange(float x, float y);
	int directionOfPlayer();
	void changeDirectionTexture(sf::Texture& playerTexture, const std::filesystem::path& animationPicture);
	bool reachingVerticalPlaceForMapChange(float TransitionPointX, float lowerTransitionPointY, float higherTransitionPointY, float mapSizeX, float mapSizeY);
	bool reachingHorizontalPlaceForMapChange(float TransitionPointY, float lowerTransitionPointX, float higherTransitionPointX, float mapSizeX, float mapSizeY);
	void playerInnerHitboxUpdate();
};


