#include <iostream>
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

bool buttonsCollision(sf::RectangleShape button, sf::Vector2i mousePos);
bool buttonsClicked(sf::RectangleShape button, sf::Vector2i mousePos);
void buttonCreation(sf::RectangleShape& button, sf::Vector2f size, sf::Vector2f position);
using namespace sf;




int main()
{
	// Create the main window and get desktop resolution
	auto desktop = VideoMode::getDesktopMode();
    unsigned int width = desktop.size.x;
    unsigned int height = desktop.size.y;
    float menuWidth = (int)width / 10 * 4;
    float menuHeight = (int)height / 10;
    float buttonWidth = (int)width / 10 * 2;
    float buttonHeight = (int)height / 10;
    RenderWindow window(VideoMode({ width, height }), "SFML window", State::Fullscreen);
    window.setFramerateLimit(60);

	//creating menu buttons and settings menu
    RectangleShape buttonMenu;
    RectangleShape buttonSettings;
    RectangleShape buttonQuit;
    RectangleShape buttonTryAgain;
    RectangleShape buttonBack;
    RectangleShape setttingsMenu;

	//button properties and creation
    buttonCreation(buttonMenu, { buttonWidth, buttonHeight }, { menuWidth,menuHeight });
    buttonCreation(buttonSettings, { buttonWidth, buttonHeight }, { menuWidth, menuHeight*3 });
    buttonCreation(buttonQuit, { buttonWidth, buttonHeight }, { menuWidth, menuHeight*5 });
    buttonCreation(buttonTryAgain, { buttonWidth, 600.f }, { 0.f,0.f });
    buttonCreation(buttonBack, { 50.f, 50.f }, { 50.f,50.f });
    buttonCreation(setttingsMenu, { 600.f, 400.f }, { 100.f,100.f });
    buttonTryAgain.setFillColor(Color::Red);
    setttingsMenu.setFillColor(Color::Blue);

	

	//background creations
    Texture bg("mapa.png");
    Sprite background(bg);
    background.setTexture(bg);
    background.setPosition(Vector2f(0, 0));
	float bgWidth = bg.getSize().x;
	float bgHeight = bg.getSize().y;

    //player creations A
    Player player;
	player.playerSizeX = 50.f;
	player.playerSizeY = 50.f;
	player.playerCreation(width / 2.f, height / 2.f);

	

    //camera view
    View view;
	view.setCenter(Vector2(player.positionX, player.positionY));
	view.setSize(Vector2f(width, height));
    
    View view2;
	view2.setCenter(Vector2f(width / 2, height / 2));
	view2.setSize(Vector2f(width, height));
   


	// Game state
    bool screenMenu = true;
    bool game = false;
    bool settings = false;

    // Start the game loop
    while (window.isOpen())

    {
		//mouse position and button collision
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
        if (Keyboard::isKeyPressed(Keyboard::Key::Escape) && game == true)
        {
            game = false;
            screenMenu = true;
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
        //
        
        //draw
        if (screenMenu == true) {
            window.setView(view2);
            window.draw(buttonMenu);
            window.draw(buttonSettings);
            window.draw(buttonQuit);
        }
        if (settings == true) {
            
            window.draw(setttingsMenu);
            window.draw(buttonBack);
        }
        if (game == true) {
            window.setView(view);
            player.move();
            player.borderCollision((int)width, (int)height, bgWidth, bgHeight);
			view.setCenter(Vector2(player.positionX, player.positionY));
			window.draw(background);
            window.draw(player.playerShape);
        }



      
        window.display();
        window.clear();



    }


}