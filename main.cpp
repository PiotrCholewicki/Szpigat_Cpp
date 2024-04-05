#include "Game.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include<string>

int main()
{

    /*
    Card newCard(Suits::clubs, CardNames::king);
    std::cout << newCard << "\n";
    Deck newDeck;
    std::cout << newDeck;
    newDeck.printSize();
    Player newbie("newbie");
    Player pro("pro");
    for (int i = 0; i < 4; i++) {
        newbie.drawCard(newDeck);
        pro.drawCard(newDeck);
    }
    newbie.display();
    pro.display();
    newDeck.printSize();
    */
    Game game;
    while (game.isRunning()) {
        game.update();

        game.render();
    }
    return 0;
}