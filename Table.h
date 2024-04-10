#pragma once
#include "Player.h"
class Game;
class Table
{
public:
	Table();
	Table(std::vector<Player> gamePlayers);
	int getRoundId();
	std::vector<Player> getPlayers();
	void initVariables();
	Card getTopCardFromStack(); //for rendering last card 
	friend class Game;
private:
	void dealCardsForPlayers();
	void dealOneCard();
	void initDecks();
	void initRoundId();
	int passTurn();
	std::vector<Player> players;
	Deck drawableCards;
	Deck stackOfCards;
	int round_id;
	
};

