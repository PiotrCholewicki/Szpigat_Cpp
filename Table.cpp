#include "Table.h"

Table::Table()
{
	this->initVariables();
}

int Table::getRoundId()
{
	return round_id;
}

void Table::dealCardsForPlayers()
{
	//in the beggining of the round deal 4 cards for each player
	for (auto& it : players) {
		
		for(int i = 0; i < 4; i++){
			
			if (i == 2 or i == 3) {
				//hide two cards for player
				bool flag = true;
				drawableCards.getTopCard().setVisibility(flag);
				
			}
			std::cout << drawableCards.getTopCard().isVisibleForAll() << ' ' << drawableCards.getTopCard() << std::endl;
			it.drawCard(drawableCards);
		}
	}
	
}

void Table::dealOneCard()
{
	if (drawableCards.getSize() > 0) {
		stackOfCards.putCard(drawableCards.dealTopCard()); //put card of stack from drawableCards (playable deck)
	}
	else {
		//if there are no more cards to draw, refill drawable cards with cards that were played during the game (stackOfCards)
		for (int i = 0; i < stackOfCards.getSize(); i++) {
			
			drawableCards.putCard(stackOfCards.dealTopCard()); 
			
		}
		drawableCards.shuffle();
		stackOfCards.putCard(drawableCards.dealTopCard());
	}
}

void Table::initVariables()
{
	int amountOfPlayers = 4;
	this->initDecks();
	this->initPlayers(amountOfPlayers);
	this->initRoundId();
	this->dealCardsForPlayers();
	
}

void Table::initPlayers(int n)
{
	for (int i = 0; i < n; i++) {
		Player p1("PLAYER_NAME", i);
		this->players.push_back(p1);
	}
}

void Table::initDecks()
{
	this->drawableCards.shuffle();
	this->stackOfCards.clear();
}

void Table::initRoundId()
{
	this->round_id = 0;
}

int Table::passTurn()
{
	round_id += 1;
	round_id %= players.size();
	return round_id;
}

std::vector<Player> Table::getPlayers()
{
	return players;
}
