#pragma once
#include<iostream>
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
    int setOwnerId(int id); //in future replace into Player
    bool& setVisibility(bool visibility);
    friend std::ostream& operator<<(std::ostream& s, const Card& c);
private:
    Suits suit;
    CardNames cardName;
    int value;
    bool isVisibleForEveryone;
    int owner_id; //replace into Player
};
