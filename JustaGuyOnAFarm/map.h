#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

struct Map {
	sf::Texture texture;
	float bgWidth;
	float bgHeight;
};
extern Map village;
extern Map farm;
extern Map home;
enum class MapState { village, farm, home };