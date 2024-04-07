#pragma once
#include "Player.h"
class Table
{
public:
	Table();
	Table(std::vector<Player> gamePlayers);
	int getRoundId();
	void dealCardsForPlayers();
	void dealOneCard();
	std::vector<Player> getPlayers();
	int getStage();
	int setStage(int stage_);
	void initVariables();
private:
	
	void initMissingPlayers(int n);
	void initDecks();
	void initRoundId();
	int passTurn();
	std::vector<Player> players;
	Deck drawableCards;
	Deck stackOfCards;
	int round_id;
	int stage;
};

