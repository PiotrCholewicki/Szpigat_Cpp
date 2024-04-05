#pragma once
#include "Player.h"
class Table
{
public:
	Table();
	int getRoundId();
	void dealCardsForPlayers();
	void dealOneCard();
	std::vector<Player> getPlayers();
	int getStage();
	int setStage(int stage_);
	void initVariables();
private:
	
	void initPlayers(int n);
	void initDecks();
	void initRoundId();
	int passTurn();
	std::vector<Player> players;
	Deck drawableCards;
	Deck stackOfCards;
	int round_id;
	int stage;
};

