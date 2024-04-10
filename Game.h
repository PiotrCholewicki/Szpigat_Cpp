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
#include <sstream>
class Game {
private:
	
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	

	//std::vector<Player> players;
	Table table;
	Player me; //the one you play 
	std::vector<Player> allPlayers; //for future online feature
	int idForPlayer; //automatically set players id
	int stage;
	void initVariables();
	void initWindow();
	void initPlayers();
	std::vector<sf::Sprite> cardShapes;
	sf::Font roboto;
	sf::Text loginText;
	std::ostringstream oss;

public:
	Game();
	virtual ~Game();
	//Accesors
	const bool isRunning() const;
	//Functions
	void pollEvents();
	void updateMousePositions();
	void startRound();
	void updateLoginScreen();
	//in future, split loginscreen into seperate functions
	void updateLoginText();
	void initializeGameTable();
	void processPlayerInput();
	void updateCardOnclick();

	void addCardShapes(sf::Sprite cardToAdd);
	void update();
	void renderLoginScreen();
	void renderPlayerCards();
	void renderLastCardOnStack();
	
	void render();
};