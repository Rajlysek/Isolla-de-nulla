#include "hitbox.h"
#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
void hitbox::OuterHitboxCreation(float posX, float posY, float sizX, float sizY)
{
	hitboxShape.setSize({ sizX, sizY });
	hitboxShape.setPosition({ posX, posY });
	hitboxShape.setFillColor(sf::Color::Transparent);
}
void hitbox::OuterHitboxCreation() 
{

}
void hitbox::hitboxUpdate(float posX, float posY)
{
	hitboxShape.setPosition({ posX, posY });
}
