#pragma once
#include<iostream>
#include "Deck.h"
std::ostream& operator<<(std::ostream& s, const Card& card)
{
    // Output the suit and card name of the card
    switch (card.suit) {
    case Suits::hearts:
        s << "Hearts ";
        break;
    case Suits::clubs:
        s << "Clubs ";
        break;
    case Suits::spades:
        s << "Spades ";
        break;
    case Suits::diamonds:
        s << "Diamonds ";
        break;
    }

    switch (card.cardName) {
    case CardNames::ace:
        s << "Ace";
        break;
    case CardNames::two:
        s << "Two";
        break;
    case CardNames::three:
        s << "Three";
        break;
    case CardNames::four:
        s << "Four";
        break;
    case CardNames::five:
        s << "Five";
        break;
    case CardNames::six:
        s << "Six";
        break;
    case CardNames::seven:
        s << "Seven";
        break;
    case CardNames::eight:
        s << "Eight";
        break;
    case CardNames::nine:
        s << "Nine";
        break;
    case CardNames::ten:
        s << "Ten";
        break;
    case CardNames::jack:
        s << "Jack";
        break;
    case CardNames::queen:
        s << "Queen";
        break;
    case CardNames::king:
        s << "King";
        break;
    }

    return s;
}