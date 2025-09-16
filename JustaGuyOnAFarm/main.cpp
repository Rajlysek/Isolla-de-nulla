#include <iostream>
#include "Player.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
bool buttonsCollision(sf::RectangleShape button, sf::Vector2i mousePos);
bool buttonsClicked(sf::RectangleShape button, sf::Vector2i mousePos);
void buttonCreation(sf::RectangleShape& button, sf::Vector2f size, sf::Vector2f position);
using namespace sf;
int width = 800;
int height = 600;

int main()
{
    // Create the main window
    RenderWindow window(VideoMode({ 800, 600 }), "SFML window", Style::Default);
    window.setFramerateLimit(60);
    //creating menu buttons
    RectangleShape buttonMenu;
    RectangleShape buttonSettings;
    RectangleShape buttonQuit;
    RectangleShape buttonTryAgain;
    RectangleShape buttonBack;
    RectangleShape setttingsMenu;
    //button properties
    buttonCreation(buttonMenu, { 200.f, 50.f }, { 300.f,100.f });
    buttonCreation(buttonSettings, { 200.f, 50.f }, { 300.f,200.f });
    buttonCreation(buttonQuit, { 200.f, 50.f }, { 300.f,300.f });
    buttonCreation(buttonTryAgain, { 800.f, 600.f }, { 0.f,0.f });
    buttonCreation(buttonBack, { 50.f, 50.f }, { 50.f,50.f });
    buttonCreation(setttingsMenu, { 600.f, 400.f }, { 100.f,100.f });
    buttonTryAgain.setFillColor(Color::Red);
    setttingsMenu.setFillColor(Color::Blue);

    //player creation
    Player player;
    player.positionX = 400.f;
    player.positionY = 300.f;
    player.playerShape.setSize({ 50.f, 50.f });
    player.playerShape.setPosition({ player.positionX, player.positionY });



    bool screenMenu = true;
    bool game = false;
    bool settings = false;

    // Start the game loop
    while (window.isOpen())

    {

        Vector2i mousePos = sf::Mouse::getPosition(window);
        if (buttonMenu.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && screenMenu == true)
        {
            std::cout << "Click" << std::endl;
            screenMenu = false;
            game = true;
        }

        if (buttonSettings.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && screenMenu == true)
        {
            screenMenu = false;
            settings = true;
        }
        if (buttonBack.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && settings == true)
        {
            screenMenu = true;
            settings = false;
        }
        if (buttonQuit.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && screenMenu == true)
        {
            window.close();
        }



        // Process events

        while (const std::optional event = window.pollEvent())

        {

            // Close window: exit

            if (event->is<Event::Closed>()) {

                window.close();

            }

        }
        // Clear screen

        window.clear();
        //draw
        if (screenMenu == true) {
            window.draw(buttonMenu);
            window.draw(buttonSettings);
            window.draw(buttonQuit);
        }
        if (settings == true) {
            window.draw(setttingsMenu);
            window.draw(buttonBack);
        }
        if (game == true) {
            player.move();
            player.borderCollision(800, 600);
            window.draw(player.playerShape);

        }




        window.display();



    }


}