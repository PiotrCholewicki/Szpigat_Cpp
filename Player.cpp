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
	drawnCard.setOwnerId(this->id); // Set owner of card
	this->playersHand.push_back(drawnCard); // Add card to players hand
	
}

int Player::getPoints()
{
	return points;
}

std::vector<Card> Player::getCards() const
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

std::ostream& operator<<(std::ostream& s, const Player& p)
{
	s << p.id << ' ' << p.name << ' ';
	for (const auto& card : p.playersHand) {
		s << card << ' ';
	}
	return s;
}

