#include "Card.h"
#include<SFML/Graphics.hpp>
#include<thread>
#include<chrono>

Card::Card(Suits s, CardNames c) : suit(s), cardName(c), isVisibleForEveryone(false), owner_id(-100), posX(0), posY(0) //default owner,change it later
{       //according to the game rules, set the values of cards
        switch (c) {
        case CardNames::ace:
            value = 0;
            break;
        case CardNames::two:
            value = 2;
            break;
        case CardNames::three:
            value = 3;
            break;
        case CardNames::four:
            value = 4;
            break;
        case CardNames::five:
            value = 5;
            break;
        case CardNames::six:
            value = 6;
            break;
        case CardNames::seven:
            value = 7;
            break;
        case CardNames::eight:
            value = 8;
            break;
        case CardNames::nine:
            value = 9;
            break;
        case CardNames::ten:
            value = 10;
            break;
        case CardNames::jack:
            value = 10;
            break;
        case CardNames::queen:
            value = 10;
            break;
        case CardNames::king:
            // Kings value dependent on suits
            if (s == Suits::clubs || s == Suits::diamonds)
                value = 10; 
            else if (s == Suits::spades)
                value = 1;
            else if (s == Suits::hearts)
                value = 13;
            break;
        }
}

int Card::getValue() const
{
    return value;
}

std::string Card::getFileName() const
{
    std::string cardValue;
    switch (cardName) {
    case CardNames::ace:
        cardValue = "ace";
        break;
    case CardNames::two:
        cardValue = "2";
        break;
    case CardNames::three:
        cardValue = "3";
        break;
    case CardNames::four:
        cardValue = "4";
        break;
    case CardNames::five:
        cardValue = "5";
        break;
    case CardNames::six:
        cardValue = "6";
        break;
    case CardNames::seven:
        cardValue = "7";
        break;
    case CardNames::eight:
        cardValue = "8";
        break;
    case CardNames::nine:
        cardValue = "9";
        break;
    case CardNames::ten:
        cardValue = "10";
        break;
    case CardNames::jack:
        cardValue = "jack";
        break;
    case CardNames::queen:
        cardValue = "queen";
        break;
    case CardNames::king:
        cardValue = "king";
        break;
    }

    std::string cardSuit;
    switch (suit) {
    case Suits::hearts:
        cardSuit = "hearts";
        break;
    case Suits::clubs:
        cardSuit = "clubs";
        break;
    case Suits::spades:
        cardSuit = "spades";
        break;
    case Suits::diamonds:
        cardSuit = "diamonds";
        break;
    }

    return "img/" + cardValue + "_of_" + cardSuit + ".png";
}

const bool Card::isVisibleForAll() const
{
    return isVisibleForEveryone;
}

void Card::setPosition(float posX_, float posY_)
{
    posX = posX_;
    posY = posY_;
    
}

int& Card::setOwnerId(const int &id)
{
    this->owner_id = id;
    return owner_id;
}

bool& Card::setVisibility(bool visibility)
{
    
    Card::isVisibleForEveryone = visibility;
    return isVisibleForEveryone;
}

const int Card::getOwnerId()
{
    return owner_id;
}

void Card::setSprite(sf::Sprite spriteToSet)
{
    this->cardsSprite = spriteToSet;
    //this->texture.
}

float Card::getPosX()
{
    return posX;
}
float Card::getPosY()
{
    return posY;
}

void Card::makeCardVisibleFor5Seconds()
{
    
}


sf::Sprite Card::getSprite()
{
    return sf::Sprite();
}

bool Card::contains(sf::Vector2f point) const
{
    return false;
}

bool Card::operator==(const Card& other) const
{
    return (suit == other.suit) && (cardName == other.cardName);
}


std::ostream& operator<<(std::ostream& s, const Card& c) {
    switch (c.cardName) {
    case CardNames::ace:
        s << "Ace of ";
        break;
    case CardNames::two:
        s << "Two of ";
        break;
    case CardNames::three:
        s << "Three of ";
        break;
    case CardNames::four:
        s << "Four of ";
        break;
    case CardNames::five:
        s << "Five of ";
        break;
    case CardNames::six:
        s << "Six of ";
        break;
    case CardNames::seven:
        s << "Seven of ";
        break;
    case CardNames::eight:
        s << "Eight of ";
        break;
    case CardNames::nine:
        s << "Nine of ";
        break;
    case CardNames::ten:
        s << "Ten of ";
        break;
    case CardNames::jack:
        s << "Jack of ";
        break;
    case CardNames::queen:
        s << "Queen of ";
        break;
    case CardNames::king:
        s << "King of ";
        break;
    }

    switch (c.suit) {
    case Suits::hearts:
        s << "Hearts";
        break;
    case Suits::clubs:
        s << "Clubs";
        break;
    case Suits::spades:
        s << "Spades";
        break;
    case Suits::diamonds:
        s << "Diamonds";
        break;
    }
    

    return s;
}



