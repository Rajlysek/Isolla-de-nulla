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
void camera::borderCollisionView(float playerPosX, float playerPosY,unsigned int screenSizeX, unsigned int screenSizeY, float backgroundWidth, float backgroundHeight, sf::View& view)
{
	if(playerPosX < screenSizeX / 2 && playerPosY < screenSizeY / 2 )
	{
		float cameraPosX = screenSizeX / 2;
		float cameraPosY = screenSizeY / 2;
		view.setCenter(sf::Vector2(cameraPosX, cameraPosY));
	}
	else if (playerPosX > backgroundWidth - (screenSizeX / 2) && playerPosY > backgroundHeight - (screenSizeY / 2))
		{
			float cameraPosX = backgroundWidth - (screenSizeX / 2);
			float cameraPosY = backgroundHeight - (screenSizeY / 2);
			view.setCenter(sf::Vector2(cameraPosX, cameraPosY));
		}
	else if (playerPosX < screenSizeX / 2 && playerPosY > backgroundHeight - (screenSizeY / 2)) {
		float cameraPosX = screenSizeX / 2;
		float cameraPosY = backgroundHeight - (screenSizeY / 2);
		view.setCenter(sf::Vector2(cameraPosX, cameraPosY));
	}
	else if(playerPosY < screenSizeY / 2 && playerPosX > backgroundWidth - (screenSizeX / 2))
	{
		float cameraPosY = screenSizeY / 2;
		float cameraPosX = backgroundWidth - (screenSizeX / 2);
	}
	else if (playerPosX < screenSizeX / 2)
	{
		float cameraPosX = screenSizeX / 2;
		view.setCenter(sf::Vector2(cameraPosX, playerPosY));

	}
	else if (playerPosY < screenSizeY / 2)
	{
		float cameraPosY = screenSizeY / 2;
		view.setCenter(sf::Vector2(playerPosX, cameraPosY));

	}


	else if (playerPosX > backgroundWidth - (screenSizeX / 2))
	{
		float cameraPosX = backgroundWidth - (screenSizeX / 2);
		view.setCenter(sf::Vector2(cameraPosX, playerPosY));
	}
	else if (playerPosY > backgroundHeight - (screenSizeY/2))
	{
		float cameraPosY = backgroundHeight - (screenSizeY / 2);
		view.setCenter(sf::Vector2(playerPosX, cameraPosY));
	}
	else
	{
		view.setCenter(sf::Vector2(playerPosX, playerPosY));
	}
	
}
