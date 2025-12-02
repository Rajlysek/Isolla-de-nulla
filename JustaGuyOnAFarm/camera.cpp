	#include <iostream>
	#include "Player.h"
	#include <SFML/Window.hpp>
	#include <SFML/Audio.hpp>
	#include <SFML/Graphics.hpp>
	#include <SFML/Window/Keyboard.hpp>
	#include "camera.h"



void camera::update(float playerPosX, float playerPosY, sf::View& view)
{
    view.setCenter(sf::Vector2(playerPosX, playerPosY));
}
void camera::borderCollisionView(float playerCenterX, float playerCenterY, float playerPosX, float playerPosY, int screenSizeX, int screenSizeY, float backgroundWidth, float backgroundHeight, sf::View& view)//pres colission?
{
	int lowerXHalf = screenSizeX / 2;
	int lowerYHalf = screenSizeY / 2; //240
	int biggerXHalf = backgroundWidth - lowerXHalf;
	int biggerYHalf = backgroundHeight - lowerYHalf; //480
	sf::Vector2f center = view.getCenter();
	center.x = playerCenterX; //set camera center to player center, if not in border collision area
	center.y = playerCenterY;
	if (playerCenterX <= lowerXHalf) center.x = lowerXHalf; // if player center position is less than half screen size, set camera center to half screen size
	if (playerCenterY <= lowerYHalf) center.y = lowerYHalf;

	if (playerCenterX >= biggerXHalf) center.x = biggerXHalf;
	if (playerCenterY >= biggerYHalf) center.y = biggerYHalf;

	view.setCenter(center);


	

	
}
