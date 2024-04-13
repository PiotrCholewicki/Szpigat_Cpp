#include "Player.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

Player::Player() : points(0)
{

}

Player::Player(std::string name_, int id_) : points(0), name(name_), id(id_)
{
}

void Player::drawCard(Deck &d)
{
	Card drawnCard = d.dealTopCard(); // Draw card from deck
	drawnCard.setOwnerId(this->id*(1));// Set ownership of card
	this->playersHand.push_back(drawnCard); // Add card to players hand
	


	

}


void Player::moveCard(const Card& toMove, Deck& toPut){
	auto it = std::find(playersHand.begin(), playersHand.end(), toMove); // ZnajdŸ kartê w rêce gracza
	if (it != playersHand.end()) { // Jeœli karta zosta³a znaleziona
		toPut.putCard(toMove); // Umieœæ kartê na stosie
		playersHand.erase(it); // Usuñ kartê z rêki gracza
	}
	else {
		std::cout << "Card not found in hand!" << std::endl; // Komunikat, gdy karta nie zosta³a znaleziona w rêce gracza
	}
}

int Player::getPoints()
{
	return points;
}

const std::vector<Card>& Player::getCards()
{
	return playersHand;
}

int Player::getId()
{
	
	return id;
}

std::string Player::getName()
{
	return name;
}

std::string Player::setName(std::string nameToSet)
{
	name = nameToSet;
	return name;
}

int Player::setId(int idToSet)
{
	id = idToSet;
	return id;
}

void Player::displayPlayerCards()
{
	for (int i = 0; i < playersHand.size(); i++) {
		std::cout << playersHand[i] <<playersHand[i].getOwnerId() << std::endl;
	}

}

std::ostream& operator<<(std::ostream& s, const Player& p)
{
	s << p.id << ' ' << p.name << ' ';

	return s;
}

