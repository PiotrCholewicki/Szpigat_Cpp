#pragma once
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Player.h"
#include "Display.h"
#include "Deck.h"
#include "Card.h"
#include "Table.h"
class Game {
private:
	
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	//Game variables
	//move to the table
	//Deck drawableCards;
	//Deck stackOfCards;
	//std::vector<Player> players;
	Table table;
	Player me; //the one you play 
	void initVariables();
	void initWindow();
	int stage;
	

public:
	Game();
	virtual ~Game();
	//Accesors
	const bool isRunning() const;
	//Functions
	void pollEvents();
	void updateMousePositions();

	void update();
	void renderPlayerCards();
	void render();
};