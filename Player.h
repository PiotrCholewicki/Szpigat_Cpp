#pragma once
#include "Deck.h"

class Player
{
public:
	Player();
	Player(std::string name_, int id_);
	void drawCard(Deck &d);
	int getPoints();
	std::vector<Card> getCards() const;
	int getId();
	friend std::ostream& operator<<(std::ostream& s, const Player& p);
private:
	std::string name;
	int points;
	std::vector<Card> playersHand;
	int id;

};

