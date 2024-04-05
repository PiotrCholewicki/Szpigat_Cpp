#include "Deck.h"
#include "Display.h"
Deck::Deck()
{
    // Initialize the deck with all possible combinations of suits and card names
    for (int s = static_cast<int>(Suits::hearts); s <= static_cast<int>(Suits::diamonds); ++s) {
        for (int c = static_cast<int>(CardNames::ace); c <= static_cast<int>(CardNames::king); ++c) {
            Card card(static_cast<Suits>(s), static_cast<CardNames>(c));
            cards.push_back(card);
        }
    }
    for (int i = 0; i < 10; i++) {
        this->shuffle();
    }
    
}
Deck::~Deck() {
	
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

void Deck::printSize()
{
    std::cout << cards.size();
}



Card Deck::dealTopCard()
{
    //deal card that is on the top of the deck
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;

}

void Deck::clear()
{
    this->cards.clear();
}

bool Deck::isEmpty() const
{
    return cards.empty();
}

Card Deck::putCard(Card c)
{
    cards.push_back(c);
    return c;
}

int Deck::getSize()
{
    return cards.size();
}

Card& Deck::getTopCard()
{
    return cards[cards.size() - 1];
}

std::vector<Card> Deck::getCards() const
{
    return cards;
}

std::ostream& operator<<(std::ostream &s, const Deck& deck)
{
    for (auto& card : deck.getCards()) {
        s << card << ' ';
    }
    return s;
}
