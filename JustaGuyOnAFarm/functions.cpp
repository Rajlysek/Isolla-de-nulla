#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

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


//void loadVillage() {
//	sf::Texture bg("mapa.png");
//	sf::Sprite background(bg);
//	background.setTexture(bg);
//	background.setPosition(sf::Vector2f(0, 0));
//	float bgWidth = bg.getSize().x;
//	float bgHeight = bg.getSize().y;
//
//}


