#include "Player.h"

Player::Player() : points(0)
{

}

Player::Player(std::string name_, int id_) : points(0), name(name_), id(id_)
{
}

void Player::drawCard(Deck &d)
{
	Card drawnCard = d.dealTopCard(); // Draw card from deck
	drawnCard.setOwnerId(this->id);
	drawnCard.setVisibility(true); // Set ownership of card
	this->playersHand.push_back(drawnCard); // Add card to players hand

}

void Player::moveCard(const Card& toMove, Deck& toPut){
	auto it = std::find(playersHand.begin(), playersHand.end(), toMove); // Znajd� kart� w r�ce gracza
	if (it != playersHand.end()) { // Je�li karta zosta�a znaleziona
		toPut.putCard(toMove); // Umie�� kart� na stosie
		playersHand.erase(it); // Usu� kart� z r�ki gracza
	}
	else {
		std::cout << "Card not found in hand!" << std::endl; // Komunikat, gdy karta nie zosta�a znaleziona w r�ce gracza
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
		std::cout << playersHand[i] << std::endl;
	}
}

std::ostream& operator<<(std::ostream& s, const Player& p)
{
	s << p.id << ' ' << p.name << ' ';

	return s;
}

