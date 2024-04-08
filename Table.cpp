#include "Table.h"

Table::Table()
{
	
}

Table::Table(std::vector<Player> gamePlayers)
{
	for (int i = 0; i < gamePlayers.size(); i++) {
		players.push_back(gamePlayers[i]);
	}
	
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
			drawableCards.getTopCard().setOwnerId(it.getId()); 
			std::cout << drawableCards.getTopCard().isVisibleForAll() << ' ' << drawableCards.getTopCard()<< ' '<<drawableCards.getTopCard().getOwnerId() << std::endl;
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
	//int amountOfPlayers = 4 - players.size();
	this->initDecks();
	//this->initMissingPlayers(amountOfPlayers);
	this->initRoundId();
	this->dealCardsForPlayers();
	
}

void Table::playerTurn(int currentPlayerId)
{

}

Card Table::getTopCardFromStack()
{
	return stackOfCards.getTopCard();
}


/*
void Table::initPlayers(int n)
{
	for (int i = 0; i < n; i++) {
		Player p1("PLAYER_NAME", i);
		this->players.push_back(p1);
	}
}
*/


void Table::initMissingPlayers(int n)
{

	
}

void Table::initDecks()
{
	this->drawableCards.shuffle();
	this->stackOfCards.clear();
	//draw first card on the table
	this->stackOfCards.putCard(drawableCards.dealTopCard());
}

void Table::initRoundId()
{
	this->round_id = 0;
}

int Table::passTurn()
{
	round_id += 1;
	if (round_id >= players.size()) {
		round_id = 0;
	}
	return round_id;
}

std::vector<Player> Table::getPlayers()
{
	return players;
}

int Table::getStage()
{
	return stage;
}

int Table::setStage(int stage_)
{
	stage = stage_;
	return stage;
}
