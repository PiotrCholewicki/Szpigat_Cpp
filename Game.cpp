#include "Game.h"
#include<thread>
void Game::initVariables()
{
    this->stage = 0;
    this->idForPlayer = 1;
    this->me = Player("STARTING_GAME", -1);
    this->round_id = 0;
    this->nextRound = false;
    this->clicksOnTurn = 0;
}

void Game::initWindow()
{
    this->videoMode.width = 1080;
    this->videoMode.height = 720;
    this->window = new sf::RenderWindow(this->videoMode, "Szpigat", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
    this->roboto.loadFromFile("font-roboto\\Roboto-light.ttf");
    this->loginText.setFont(roboto);
    
    
}

void Game::initPlayers()
{
    int samplePlayerId = 10;
    //for now create table with only one player, then update it for multiplayer 
    for (int i = 0; i < 3; i++) {
        Player samplePlayer("SAMPLE_PLAYER", samplePlayerId);
        allPlayers.push_back(samplePlayer);
        samplePlayerId++;
    }
}


Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

const bool Game::isRunning() const
{
    return this->window->isOpen();
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed: { //closing on clicking the top right corner "X"
                this->window->close();
                break;
            }
            case sf::Event::KeyPressed: { //close on clicking escape
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
            }
            case sf::Event::MouseButtonPressed: {
                if (ev.mouseButton.button == sf::Mouse::Left) {
                    // Play card on the table

                }
                break;
            }

        }
    }
}

void Game::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
    
}

void Game::startRound()
{
    
    Table gameTable(allPlayers);
    
    this->table = gameTable;

    this->table.initVariables();
    this->displayCardsForAllPlayers();
    this->playerTurn();
    
    

}

void Game::playerTurn()
{
    this->clicksOnTurn = 0;
    table.getPlayers()[round_id].drawCard(table.drawableCards);
    std::cout << "Tura gracza: " << table.getPlayers()[round_id] << std::endl;
    //table.getPlayers()[round_id].displayPlayerCards();




}

void Game::endTurn()
{
    round_id++;
    if (round_id >= allPlayers.size()) {
        round_id = 0;
    }
}

void Game::updateLoginScreen()
{
    std::string name;
    this->oss.str("");
    this->oss << "Enter your name: ";
    this->loginText.setString(this->oss.str());
    this->window->draw(this->loginText);
    this->window->display();
    std::cin >> name;
    this->me.setName(name);
    this->me.setId(idForPlayer);
    this->allPlayers.push_back(me);
    this->idForPlayer++;
    this->stage++;
    this->initPlayers();
    
    this->startRound();

}



void Game::updateCardOnClick()
{
    sf::RectangleShape endTurnButton(sf::Vector2f(50.f, 50.f));
    endTurnButton.setPosition(1030.f, +0.f); 
    // Check if the left mouse button is pressed
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        for (int i = 0; i < this->cardShapes.size(); i++) {
            if (this->cardShapes[i].getGlobalBounds().contains(this->mousePosView)) {
                std::cout << "kliknieto na karte: " << cardShapes[i].getPosition().x << ' ' << cardShapes[i].getPosition().y << std::endl;
                
                //find card while its position is known
                int cardIndex = cardShapes[i].getPosition().x / 100.f;
                int playerIndex = cardShapes[i].getPosition().y / 150.f;
                auto& currentPlayer = table.getPlayers()[playerIndex];

                currentPlayer.moveCard(currentPlayer.getCards()[cardIndex], table.stackOfCards);
                nextRound = true;
                sf::sleep(sf::milliseconds(250));
                if (nextRound) {
                    endTurn();
                    playerTurn();
                    nextRound = false;
                }
                break;
            }
            else {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (endTurnButton.getGlobalBounds().contains(this->mousePosView)) {
                        
                        nextRound = true;
                        sf::sleep(sf::milliseconds(250));
                        if (nextRound) {
                            endTurn();
                            playerTurn();
                            nextRound = false;
                        }
                        break;

                    }
                }
            }

        }
        
    }

}

void Game::displayCardsForAllPlayers()
{
    // Utwórz zegar do œledzenia czasu wykonywania funkcji
    sf::Clock displayClock;
    const sf::Time displayDuration = sf::seconds(5); // Czas trwania wyœwietlania informacji: 5 sekund

    // Pêtla po wszystkich graczach i ich kartach
    for (auto& player : allPlayers) {
        for (auto card : player.getCards()) {
            std::cout << "raz dwa trzy" << std::endl;
            // Tutaj mo¿esz wykonaæ inne operacje na kartach, jeœli to konieczne

            // SprawdŸ, czy nie min¹³ jeszcze czas wyœwietlania informacji
            if (displayClock.getElapsedTime() >= displayDuration) {
                return; // Jeœli min¹³ czas, wyjdŸ z pêtli
            }
        }
    }
}


void Game::addCardShapes(sf::Sprite cardToAdd)
{
    this->cardShapes.push_back(cardToAdd);
}

void Game::update()
{
    this->pollEvents();
    this->updateMousePositions();
    
    if (this->stage == 0) {
        this->updateLoginScreen();
        
    }
    if (this->stage == 1) {
        this->updateCardOnClick();
    }
    
}

void Game::renderLoginScreen()
{
    this->oss.str("");
    this->loginText.setString(this->oss.str());
    this->window->draw(this->loginText);
}

void Game::renderPlayerCards() {
    sf::Texture texture;
    float posX = 0;
    float posY = 0;
    for (auto& player : table.getPlayers()) {
        
        for (auto card : player.getCards()) {
            
            if (card.isVisibleForAll() or card.getOwnerId() == me.getId() ) { 
                
                card.setPosition(posX, posY); 
                if (texture.loadFromFile(card.getFileName())) {
                    sf::Sprite sprite(texture);
                    sprite.setPosition(card.getPosX(), card.getPosY());
                    
                    this->addCardShapes(sprite);
                    this->window->draw(sprite);
                    posX += 100;
                }
            }
            else {
                if (texture.loadFromFile("img/back.png")) {
                    sf::Sprite sprite(texture);
                    sprite.setPosition(posX, posY);
                    
                    this->addCardShapes(sprite);
                    this->window->draw(sprite);
                    posX += 100;
                }
            }
        }
        posX = 0;
        posY += 150;
    }
}



void Game::renderLastCardOnStack()
{
    sf::Texture texture;
    if (texture.loadFromFile(table.getTopCardFromStack().getFileName())) {
        float posX = 683.f;
        float posY = 250.f;
        sf::Sprite sprite(texture);
        sprite.setPosition(posX, posY);
        
        this->window->draw(sprite);
    }
}

void Game::renderButton()
{
    sf::RectangleShape endTurnButton(sf::Vector2f(50.f, 50.f));
    endTurnButton.setFillColor(sf::Color(255,155,0));
    endTurnButton.setPosition(1030.f, 0.f);
    sf::Text endTurnText("End\nTurn", roboto, 20);
    endTurnText.setFillColor(sf::Color::Black);
    endTurnText.setPosition(1031.f, 1.f);

    
    this->window->draw(endTurnButton);
    this->window->draw(endTurnText);
}



void Game::render()
{
    
    if (stage == 0) {
        
        this->renderLoginScreen();
        this->window->display();
    }
    else if (stage == 1) {

        this->window->clear(sf::Color(0, 128, 43));
        this->renderPlayerCards();
        this->renderLastCardOnStack();
        this->renderButton();
        this->window->display();

    }

    //this->window->display();
}
