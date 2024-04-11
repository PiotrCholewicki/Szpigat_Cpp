#pragma once
#include "Card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include<SFML/Graphics.hpp>
class Game;

class Deck {
public:
	Deck();
	~Deck();
	void shuffle();
	void printSize();
	Card dealTopCard();
	void clear();
	bool isEmpty() const;
	Card putCard(Card c); 
	int getSize();
	Card& getTopCard();
	std::vector<Card> getCards() const;
	friend std::ostream& operator<<(std::ostream s, const Deck& deck);
	friend class Game;
private:
	std::vector<Card> cards;

};

