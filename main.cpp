#include "Game.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include<string>

int main()
{
    Game game;
    while (game.isRunning()) {

        game.update();

        game.render();
        
    }
    return 0;
}