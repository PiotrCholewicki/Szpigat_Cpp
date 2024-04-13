#pragma once
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Player.h"

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
	
	Table table;
	Player me; //the one you play 
	Player* currentPlayer; 
	std::vector<Player> allPlayers; //for future online feature
	std::vector<sf::Sprite> cardShapes;
	sf::Font roboto;
	sf::Text loginText;
	std::ostringstream oss;
	int clicksOnTurn;
	bool nextRound;

	int idForPlayer; //automatically set players id
	int stage;
	int round_id;
	void initVariables();
	void initWindow();
	void initPlayers();


public:
	Game();
	virtual ~Game();
	//Accesors
	const bool isRunning() const;
	//Functions
	void pollEvents();
	void updateMousePositions();
	void startRound();
	void playerTurn();
	void endTurn();
	void updateLoginScreen();
	//in future, split loginscreen into seperate functions
	void updateLoginText();
	void initializeGameTable();
	void processPlayerInput();
	void updateCardOnClick();
	void displayCardsForAllPlayers();

	void addCardShapes(sf::Sprite cardToAdd);
	void update();
	void renderLoginScreen();
	void renderPlayerCards();
	void renderLastCardOnStack();
	void renderButton();
	
	void render();
};