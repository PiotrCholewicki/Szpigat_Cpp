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
private:
	void initVariables();
	void initPlayers(int n);
	void initDecks();
	void initRoundId();
	int passTurn();
	std::vector<Player> players;
	Deck drawableCards;
	Deck stackOfCards;
	int round_id;
};

