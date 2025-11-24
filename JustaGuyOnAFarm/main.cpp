#include <iostream>
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Animation.h"
#include "hitbox.h"
#include "map.h"
#include <string>
#include <tuple>
#include "camera.h"
#include "items.h"
#include <stdlib.h>
#include <vector>
using namespace sf;
bool buttonsCollision(sf::RectangleShape button, sf::Vector2i mousePos);
bool buttonsClicked(sf::RectangleShape button, sf::Vector2i mousePos);
void buttonCreation(sf::RectangleShape& button, sf::Vector2f size, sf::Vector2f position);
void borderCollisionView(float playerPosX, float playerPosY, unsigned int windowSizeX, unsigned int windowSizeY, float backgroundSizeX, float backgroundSizeY);
void update(float playerPosX, float playerPosY, sf::View& view);

enum class gameState { menu, settings, game };
//enum class State { Default = State::Default, Fullscreen = State::Fullscreen, Close = State::Close, None = Style::None };

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

	//camera creation
    camera cam;

	//test sprite
    Texture zkouskaTexture("blok.png");
	Sprite zkouskaSprite(zkouskaTexture);
	zkouskaSprite.setPosition(Vector2f(0, 0));
	zkouskaSprite.setScale({ 2.f, 2.f });
    
	//village map loading
    village.texture.loadFromFile("mapa.png");
    village.bgWidth = village.texture.getSize().x;
    village.bgHeight = village.texture.getSize().y;

	
    //farm map loading
	farm.texture.loadFromFile("nothing.png");
    farm.bgWidth = farm.texture.getSize().x;
	farm.bgHeight = farm.texture.getSize().y;

	//background creations
    //Texture bg("mapa.png");
    Sprite villageMap(village.texture);
    villageMap.setTexture(village.texture);
    villageMap.setPosition(Vector2f(0, 0));

	Sprite farmMap(farm.texture);
	farmMap.setTexture(farm.texture);
	farmMap.setPosition(Vector2f(0, 0));

    //player creations A
    Player player;
	float playerCreationPosX = village.texture.getSize().x / 2;
    float playerCreationPosY = village.texture.getSize().y / 2;
	player.playerCreation(playerCreationPosX, playerCreationPosY);

    //texture of the player
    Texture playerTexture;
    playerTexture.loadFromFile("IdleAnimace.png");
	//setting texture to player
    player.playerShape.setTexture(&playerTexture);
	player.playerShape.setScale({ 4.5, 4.5 });
    player.playerShape.setTextureRect(sf::IntRect({ 12, 2 }, { 26, 48 })); //https://www.sfml-dev.org/tutorials/3.0/graphics/transform/#object-hierarchies-scene-graph
    int idleSizeX = player.playerShape.getSize().x;
    int idleSizeY = player.playerShape.getSize().y;

    //player's hitbox creation and setting up
    hitbox playerHitbox;
    playerHitbox.OuterHitboxCreation(player.positionX, player.positionY, idleSizeX*4.5, idleSizeY*4.5);
    playerHitbox.hitboxShape.setOutlineColor(Color::Black);
    playerHitbox.hitboxShape.setOutlineThickness(1.f);
    
    Animation idleAnimation(&playerTexture, Vector2u(5, 1), 0.15f);
    float deltaTime = 0.0f;
    Clock clock;
      
    //camera view
    View view;
	view.setSize(Vector2f(width, height));
	// centering the view on the player at the start    
    View view2;
	view2.setCenter(Vector2f(width / 2, height / 2));
	view2.setSize(Vector2f(width, height));
         
	// Game state
    bool screenMenu = false;
    bool game = true;
    bool settings = false;

    gameState currentState = gameState::menu;
	MapState currentMap = MapState::village;

    buttonCreation(buttonSettings, { buttonWidth, buttonHeight }, { menuWidth, menuHeight * 3 });

    std::vector<item> itemlist;
    
    for (int i = 0; i<20; i++ )
    {
        item item;
        RectangleShape itemShape;
        item.positionXCreation(village.bgWidth);
        item.positionYCreation(village.bgHeight);
        item.itemCreation(itemShape, { Vector2f(48.f, 48.f) }, { Vector2f(item.positionX, item.positionY) });
        itemlist.push_back(item);
    }
	//item creation
    item item1;
	RectangleShape itemShape;
    item1.positionXCreation(village.bgWidth);
    item1.positionYCreation(village.bgHeight);
    item1.itemCreation(itemShape, {Vector2f( 48.f, 48.f )}, { Vector2f(item1.positionX, item1.positionY)});

    item item2;
    RectangleShape itemShape2;
    item2.positionXCreation(village.bgWidth);
    item2.positionYCreation(village.bgHeight);
    item2.itemCreation(itemShape2, { Vector2f(48.f, 48.f) }, { Vector2f(item2.positionX, item2.positionY) });
    itemShape2.setFillColor(sf::Color::Red);

   
    // Start the game loop
    while (window.isOpen())

    {
        
        deltaTime = clock.restart().asSeconds();
        idleAnimation.Update(0, deltaTime);
        player.playerShape.setTextureRect(idleAnimation.uvRect);
	    std::cout << player.playerCenterX << " " << player.playerCenterY << std::endl;
		//mouse position and button collision
        Vector2i mousePos = sf::Mouse::getPosition(window);
        
        switch (currentState) {
        //menu
        case gameState::menu:
            if (buttonMenu.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && currentState == gameState::menu)
            {
                currentState = gameState::game;
            }

            if (buttonSettings.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && currentState == gameState::menu)
            {
                currentState = gameState::settings;
            }
           
            if (buttonQuit.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && currentState == gameState::menu)
            {
                window.close();
            }
            window.setView(view2);
            window.draw(buttonMenu);
            window.draw(buttonSettings);
            window.draw(buttonQuit);
          
            break;
       
         //setting       
        case gameState::settings:
            for(const item& item: itemlist)
            {
            }
            if (buttonBack.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && currentState == gameState::settings)
            {
                currentState = gameState::menu;
                
            }
           window.draw(setttingsMenu);
           window.draw(buttonBack);
           
           break;
           
           //game
        case gameState::game:
            switch (currentMap) {
			case MapState::village:

				std::cout << rand() % int(village.bgHeight) + 1 << std::endl;
				std::cout << item1.positionX << " 123 " << item1.positionY << std::endl;
                std::cout << item2.positionX << " 456 " << item2.positionY << std::endl;
                if (Keyboard::isKeyPressed(Keyboard::Key::Escape) && game == true)
                {
                    currentState = gameState::menu;
                }
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
                
                    player.changeDirectionTexture(playerTexture, "WalkindIdleLeft.png");
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

                    player.changeDirectionTexture(playerTexture, "WalkingIdleRight.png");
                }
                else {
                    player.changeDirectionTexture(playerTexture, "IdleAnimace.png");
				}
                
                window.setView(view);
                player.move();
				playerHitbox.hitboxUpdate(player.positionX, player.positionY);
                player.borderCollision(village.bgWidth, village.bgHeight, player.playerShape.getSize().x, player.playerShape.getSize().y);
                if (player.reachingVerticalPlaceForMapChange(0, 700, 1000, village.bgWidth, village.bgHeight))
                {
                   currentMap = MapState::farm;
                }
                if (player.reachingHorizontalPlaceForMapChange(0, 700, 1000, farm.bgWidth, farm.bgHeight))
                {
                    currentMap = MapState::farm;
                } 
                item1.itemPickup(itemShape, playerHitbox.hitboxShape);
				
                //cam.borderCollisionView(player.playerSizeX, player.playerSizeY,player.positionX, player.positionY, width, height, village.bgWidth, village.bgHeight, view);
				view.setCenter(sf::Vector2f(player.playerCenterX,player.playerCenterY));
                cam.borderCollisionView(player.playerCenterX, player.playerCenterY, player.positionX, player.positionY, width, height, village.bgWidth, village.bgHeight, view);
                window.draw(villageMap);
				window.draw(zkouskaSprite);
                window.draw(player.playerShape);
				window.draw(playerHitbox.hitboxShape);
				window.draw(itemShape);
				window.draw(itemShape2);
               // std::cout << idleSizeX << std::endl;
                std::cout << player.positionX << " " << player.positionY << std::endl;
                break;
            
            case MapState::farm:
                if (Keyboard::isKeyPressed(Keyboard::Key::Escape) && game == true)
                {
                    currentState = gameState::menu;
                }
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {

                    player.changeDirectionTexture(playerTexture, "WalkindIdleLeft.png");
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

                    player.changeDirectionTexture(playerTexture, "WalkingIdleRight.png");
                }
                else {
                    player.changeDirectionTexture(playerTexture, "IdleAnimace.png");
                }

                window.setView(view);
                player.move();
                player.borderCollision(farm.bgWidth, farm.bgHeight, player.playerShape.getSize().x, player.playerShape.getSize().y);
                if (player.reachingVerticalPlaceForMapChange(farm.bgWidth-idleSizeX*4.5, 700 , 1000, farm.bgWidth, farm.bgHeight))
                {
                    currentMap = MapState::village;
                }
                if (player.reachingHorizontalPlaceForMapChange(farm.bgHeight - idleSizeY * 4.5, 700, 1000, farm.bgWidth, farm.bgHeight))
                {
                    currentMap = MapState::village;
                }
            
                cam.borderCollisionView(player.playerCenterX, player.playerCenterY, player.positionX, player.positionY, width, height, village.bgWidth, village.bgHeight, view);
                window.draw(farmMap);
                window.draw(player.playerShape);
                std::cout << idleSizeX << std::endl;
                std::cout <<farm.bgWidth << std::endl;
				std::cout << player.positionX << " " << player.positionY << std::endl;
				break;
            }
            break;
        }

        // Process events
        while (const std::optional event = window.pollEvent())

        {
            // Close window: exit
            if (event->is<Event::Closed>()) {

                window.close();

            }
        } 
        window.display();
        window.clear();

    }


}