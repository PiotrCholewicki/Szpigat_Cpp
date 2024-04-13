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
    const int getOwnerId();
    void setSprite(sf::Sprite spriteToSet);
    float getPosX();
    float getPosY();
    void makeCardVisibleFor5Seconds(); 
    const CardNames getCardName() const;
    sf::Sprite cardsSprite;
    sf::Texture texture;
    sf::Sprite getSprite(); 
    bool contains(sf::Vector2f point) const; 
    friend std::ostream& operator<<(std::ostream& s, const Card& c);
    bool operator==(const Card& other) const;
private:
    Suits suit;
    CardNames cardName;
    int value;
    bool isVisibleForEveryone;
    int owner_id; //replace into Player
    float posX;
    float posY;
};
