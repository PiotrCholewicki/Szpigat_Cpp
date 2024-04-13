#pragma once
#include "Player.h"
class Game;
class Table
{
public:
	Table();
	Table(std::vector<Player> gamePlayers);
	
	std::vector<Player>& getPlayers();
	void initVariables();
	Card getTopCardFromStack(); //for rendering last card 
	friend class Game;
	void showCardsOnRoundStart();
private:
	void dealCardsForPlayers();
	void dealOneCard();
	void initDecks();
	
	
	std::vector<Player> players;
	Deck drawableCards;
	Deck stackOfCards;
	
	
};

