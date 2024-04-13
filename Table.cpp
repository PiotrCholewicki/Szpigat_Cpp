#include "Table.h"
#include<thread>
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
			if (i == 0 or i == 1) {
				drawableCards.getTopCard().setOwnerId(it.getId());
			}
			else {
				drawableCards.getTopCard().setOwnerId(it.getId()*(-1));
			}
			//std::cout << drawableCards.getTopCard().isVisibleForAll() << ' ' << drawableCards.getTopCard()<< ' '<<drawableCards.getTopCard().getOwnerId() << std::endl;
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
	this->initDecks();

	this->dealCardsForPlayers();

	//this->showCardsOnRoundStart();
	
}


Card Table::getTopCardFromStack()
{
	return stackOfCards.getTopCard();
}

void Table::showCardsOnRoundStart()
{
	for (auto& it : players) {
		int i = 0;
		for (auto card : it.getCards()) {
			if (i == 0 or i == 1)
				card.makeCardVisibleFor5Seconds();
			i++;

		}
		
	}
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

