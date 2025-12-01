#include <iostream>
#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Animation.h"
#include "hitbox.h"
#include "map.h"
#include <string>
#include <tuple>
#include "camera.h"
#include "items.h"
#include <stdlib.h>
#include <vector>

#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>
#include "SFMLOrthogonalLayer.hpp"



#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>



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
	auto desktop = VideoMode::getDesktopMode(); //zmenit na 1280x860 nebo tak nìco 
    unsigned int width = desktop.size.x;
    unsigned int height = desktop.size.y;
    float menuWidth = (int)width / 10 * 4;
    float menuHeight = (int)height / 10;
    float buttonWidth = (int)width / 10 * 2;
    float buttonHeight = (int)height / 10;  

    RenderWindow window(VideoMode({ width, height }), "SFML window", State::Fullscreen);
    int resolutionX = 848;
    int resolutionY = 480;
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

    tmx::Map homeMap;
    homeMap.load("maps/domov.tmx");


    MapLayer layerZero(homeMap, 0);
    MapLayer layerOne(homeMap, 1);
    MapLayer layerTwo(homeMap, 2);
    MapLayer layerThree(homeMap, 3);

    sf::Clock globalClock;

	//background creationsa
    Sprite villageMap(village.texture);
    villageMap.setTexture(village.texture);
    villageMap.setPosition(Vector2f(0, 0));

	Sprite farmMap(farm.texture);
	farmMap.setTexture(farm.texture);
	farmMap.setPosition(Vector2f(0, 0));

    //player creations A
    Player player;
	float playerCreationPosX = resolutionX / 2;
    float playerCreationPosY = resolutionY / 2;
	player.playerCreation(playerCreationPosX, playerCreationPosY);

    //texture of the player
    Texture playerTexture;
    playerTexture.loadFromFile("Player_Spritesheet.png");
	//setting texture to player
    player.playerShape.setTexture(&playerTexture);
	player.playerShape.setScale({ 1.5, 1.5 });
    player.playerShape.setTextureRect(sf::IntRect({ 0, 0 }, { 48, 48 })); //https://www.sfml-dev.org/tutorials/3.0/graphics/transform/#object-hierarchies-scene-graph
    int idleSizeX = player.playerShape.getSize().x;
    int idleSizeY = player.playerShape.getSize().y;

    ////player's hitbox creation and setting up
    //hitbox playerHitbox;
    //playerHitbox.OuterHitboxCreation(player.positionX, player.positionY, idleSizeX*4.5, idleSizeY*4.5);
    //playerHitbox.hitboxShape.setOutlineColor(Color::Black);
    //playerHitbox.hitboxShape.setOutlineThickness(1.f);
    
    Animation idleAnimation(&playerTexture, Vector2u(4, 4), 0.15f);
    float deltaTime = 0.0f;
    Clock clock;

   /* sf::RectangleShape test;
    test.setSize(sf::Vector2f(32.f, 32.f));
    test.setPosition(sf::Vector2f(1500, 1500));
    test.setFillColor(sf::Color::Black);*/
      
    //camera view
    View view(sf::FloatRect({ 0.f, 0.f }, {sf::Vector2f(resolutionX, resolutionY)}));
	//view.setSize(Vector2f(resolutionX, resolutionY));
    
	// centering the view on the player at the start    
    
	
    View view2(sf::FloatRect({ 0.f, 0.f }, { sf::Vector2f(resolutionX, resolutionY) }));
    view2.setCenter(Vector2f(resolutionX / 2, resolutionY / 2));
	// Game state
    bool screenMenu = false;
    bool game = true;
    bool settings = false;

    gameState currentState = gameState::menu;
    //gameState currentState = gameState::game;
	MapState currentMap = MapState::village;

    buttonCreation(buttonSettings, { buttonWidth, buttonHeight }, { menuWidth, menuHeight * 3 });

    std::vector<item> itemlist;
    
    for (int i = 0; i<20; i++ )
    {
        item item;
        item.body.setFillColor(sf::Color::Red);
        item.positionXCreation(village.bgWidth);
        item.positionYCreation(village.bgHeight);
        item.itemCreation(item.body, { Vector2f(48.f, 48.f) }, { Vector2f(item.positionX, item.positionY) });
        itemlist.push_back(item);
    }
    float mapWidth = homeMap.getTileSize().x * homeMap.getTileCount().x;
    float mapHeight = homeMap.getTileSize().y * homeMap.getTileCount().y;
    int AnimationRow = 0;
    // Start the game loop
    while (window.isOpen())
       
    {
    


        window.setKeyRepeatEnabled(false);
        std::cout << player.playerSizeX << " " << player.playerSizeY << '\n';
        
        deltaTime = clock.restart().asSeconds();
        
        player.playerShape.setTextureRect(idleAnimation.uvRect);
	   
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
                    if (Keyboard::isKeyPressed(Keyboard::Key::Escape) && game == true)
                    {
                        currentState = gameState::menu;
                    }

                    //changing sprite's smìr??

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {

                        AnimationRow = 2;
                        idleAnimation.Update(AnimationRow, deltaTime);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

                        AnimationRow = 3;
                        idleAnimation.Update(AnimationRow, deltaTime);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {

                        AnimationRow = 1;
                        idleAnimation.Update(AnimationRow, deltaTime);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {

                        AnimationRow = 0;
                        idleAnimation.Update(AnimationRow, deltaTime);// update (whatrow to draw, delta time)
                    }
                    else if(AnimationRow == 0) {
                        idleAnimation.SetFrame(0, 0);
                    }
                    else if (AnimationRow == 1) {
                        idleAnimation.SetFrame(0, 1);
                    }
                    else if (AnimationRow == 2) {
                        idleAnimation.SetFrame(0, 2);
                    }
                    else if (AnimationRow == 3) {
                        idleAnimation.SetFrame(0, 3);
                    }

                     window.setView(view);
                     player.move();
               
                     player.borderCollision(village.bgWidth, village.bgHeight, player.playerShape.getSize().x, player.playerShape.getSize().y);
                     if (player.reachingVerticalPlaceForMapChange(0, 700, 1000, village.bgWidth, village.bgHeight))
                     {
                         currentMap = MapState::farm;
                     }
                     if (player.reachingHorizontalPlaceForMapChange(0, 700, 1000, farm.bgWidth, farm.bgHeight))
                     {
                         currentMap = MapState::farm;
                     }
                 
                     for (item& item : itemlist)
                     {
                         item.checkingItemVisibility();
                     }
                     for (item& item : itemlist)
                     {
                         item.itemPickup(player.playerOuterHitbox);
                     }
                     //cam.borderCollisionView(player.playerSizeX, player.playerSizeY,player.positionX, player.positionY, width, height, village.bgWidth, village.bgHeight, view);
                     view.setCenter(sf::Vector2f(player.playerCenterX, player.playerCenterY));
                     cam.borderCollisionView(player.playerCenterX, player.playerCenterY, player.positionX, player.positionY, resolutionX, resolutionX, mapWidth,mapHeight, view);
                     //view.setViewport(sf::FloatRect({ 0.25f, 0.25 }, { 0.5f, 0.5f }));
                     window.clear(sf::Color::Black);
                     window.draw(layerZero);
                     window.draw(layerOne);
                     window.draw(layerTwo);
                     window.draw(layerThree);
                     window.draw(zkouskaSprite);
                 
                     
                    
                     player.playerInnerHitboxUpdate();
                     window.draw(player.playerOuterHitbox);
                     window.draw(player.playerInnerHitbox);
                     //window.display();
                 

                     for (const item& item : itemlist)
                     {
                         window.draw(item.body);
                     }
                     window.draw(player.playerShape);
                     // std::cout << idleSizeX << std::endl;
                

                     break;

            case MapState::farm:
                if (Keyboard::isKeyPressed(Keyboard::Key::Escape) && game == true)
                {
                    currentState = gameState::menu;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {

                    AnimationRow = 2;
                    idleAnimation.Update(AnimationRow, deltaTime);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

                    AnimationRow = 3;
                    idleAnimation.Update(AnimationRow, deltaTime);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {

                    AnimationRow = 1;
                    idleAnimation.Update(AnimationRow, deltaTime);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {

                    AnimationRow = 0;
                    idleAnimation.Update(AnimationRow, deltaTime);// update (whatrow to draw, delta time)
                }
                else if (AnimationRow == 0) {
                    idleAnimation.SetFrame(0, 0);
                }
                else if (AnimationRow == 1) {
                    idleAnimation.SetFrame(0, 1);
                }
                else if (AnimationRow == 2) {
                    idleAnimation.SetFrame(0, 2);
                }
                else if (AnimationRow == 3) {
                    idleAnimation.SetFrame(0, 3);
                }

                window.setView(view);
                player.move();
                player.borderCollision(farm.bgWidth, farm.bgHeight, player.playerShape.getSize().x, player.playerShape.getSize().y);
                if (player.reachingVerticalPlaceForMapChange(farm.bgWidth - idleSizeX * 4.5, 700, 1000, farm.bgWidth, farm.bgHeight))
                {
                    currentMap = MapState::village;
                }
                if (player.reachingHorizontalPlaceForMapChange(farm.bgHeight - idleSizeY * 4.5, 700, 1000, farm.bgWidth, farm.bgHeight))
                {
                    currentMap = MapState::village;
                }
                player.playerInnerHitboxUpdate();
                
                cam.borderCollisionView(player.playerCenterX, player.playerCenterY, player.positionX, player.positionY, width, height, village.bgWidth, village.bgHeight, view);
                
                window.draw(farmMap);
                window.draw(player.playerOuterHitbox);
                window.draw(player.playerInnerHitbox);
                std::cout << idleSizeX << std::endl;
                window.draw(player.playerShape);
                std::cout << farm.bgWidth << std::endl;
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