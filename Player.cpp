#include "Player.h"

Player::Player() : points(0)
{

}

Player::Player(std::string name_, int id_) : points(0), name(name_), id(id_)
{
}

void Player::drawCard(Deck &d)
{
	this->playersHand.push_back(d.dealTopCard());
	
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

std::ostream& operator<<(std::ostream& s, const Player& p)
{
	s << p.id << ' ' << p.name << ' ';
	for (const auto& card : p.playersHand) {
		s << card << ' ';
	}
	return s;
}

