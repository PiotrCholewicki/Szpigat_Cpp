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
	
	this->dealCardsForPlayers();
	
}


Card Table::getTopCardFromStack()
{
	return stackOfCards.getTopCard();
}







void Table::initDecks()
{
	this->drawableCards.shuffle();
	this->stackOfCards.clear();
	//draw first card on the table
	this->stackOfCards.putCard(drawableCards.dealTopCard());
}





std::vector<Player>& Table::getPlayers()
{
	return players;
}

