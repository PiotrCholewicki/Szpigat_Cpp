#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
class Player;
enum class Suits {
    hearts,
    clubs,
    spades,
    diamonds
};

enum class CardNames {
    ace,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king
};

class Card {
public:
    
    Card(Suits s, CardNames c);
    int getValue() const;
    std::string getFileName() const;
    const bool isVisibleForAll() const;
    void setPosition(float posX_, float posY_);
    int& setOwnerId(const int& id); //in future replace into Player
    bool& setVisibility(bool visibility);
    int getOwnerId();
    void setSprite(sf::Sprite spriteToSet);
    float getPosX();
    float getPosY();
    sf::Sprite cardsSprite;
    sf::Texture texture;
    friend std::ostream& operator<<(std::ostream& s, const Card& c);

private:
    Suits suit;
    CardNames cardName;
    int value;
    bool isVisibleForEveryone;
    int owner_id; //replace into Player
    float posX;
    float posY;
};
