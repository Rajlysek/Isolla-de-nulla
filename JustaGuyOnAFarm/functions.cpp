#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <tuple>

void buttonCreation(sf::RectangleShape& button, sf::Vector2f size, sf::Vector2f position)
{
	button.setSize(size);
	button.setPosition(position);
}


bool buttonsCollision(sf::RectangleShape button, sf::Vector2i mousePos)
{
	if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
	{
		std::cout << "Collision" << std::endl;
		return true;
	}
	else {
		return false;

	}

}
bool buttonsClicked(sf::RectangleShape button, sf::Vector2i mousePos)
{
	if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		std::cout << "Click" << std::endl;
		return true;
	}
	else {
		return false;
	}
}
 float borderCollisionView(float playerPosX, float playerPosY, unsigned int windowSizeX, unsigned int windowSizeY, float backgroundSizeX, float backgroundSizeY)
{
	if (playerPosX <= windowSizeX / 2 && playerPosY <= windowSizeY / 2) 
	{
		unsigned int posX = windowSizeX / 2;
		unsigned int posY = windowSizeY / 2;
		return posX, posY;
	}
	else if (playerPosX >= backgroundSizeX - windowSizeX / 2 && playerPosY <= windowSizeY / 2) 
	{
		unsigned int posX = backgroundSizeX - windowSizeX / 2;
		unsigned int posY = backgroundSizeY -  windowSizeY / 2;
		return posX, posY;
		
	}
	else {
		unsigned int posX = playerPosX;
		unsigned int posY = playerPosY;
		return posX, posY;
	}

}

//if (player.positionX <= width / 2) {
//	float posX = width / 2;
//	view.setCenter(Vector2(posX, player.positionY));
//}
//else {
//	view.setCenter(Vector2(player.positionX, player.positionY));
//}
//if (player.positionY <= height / 2) {
//	float posY = height / 2;
//	view.setCenter(Vector2(player.positionX, posY));
//}
//else {
//	view.setCenter(Vector2(player.positionX, player.positionY));
//}

//void loadVillage() {
//	sf::Texture bg("mapa.png");
//	sf::Sprite background(bg);
//	background.setTexture(bg);
//	background.setPosition(sf::Vector2f(0, 0));
//	float bgWidth = bg.getSize().x;
//	float bgHeight = bg.getSize().y;
//
//}


