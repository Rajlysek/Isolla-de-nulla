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
void camera::borderCollisionView(float playerCenterX, float playerCenterY, float playerPosX, float playerPosY,unsigned int screenSizeX, unsigned int screenSizeY, float backgroundWidth, float backgroundHeight, sf::View& view)//pres colission?
{
	int lowerXHalf = screenSizeX / 2;
	int lowerYHalf = screenSizeY / 2;
	int biggerXHalf = backgroundWidth - lowerXHalf;
	int biggerYHalf = backgroundHeight - lowerYHalf;
	sf::Vector2f center = view.getCenter();
	center.x = playerCenterX;
	center.y = playerCenterY;
	if(playerCenterX <= lowerXHalf) center.x = lowerXHalf;
	if (playerCenterY <= lowerYHalf) center.y = lowerYHalf;

	if (playerCenterX >= biggerXHalf) center.x = biggerXHalf;
	if (playerCenterY >= biggerYHalf) center.y = biggerYHalf;

	view.setCenter(center);


	

	
}
