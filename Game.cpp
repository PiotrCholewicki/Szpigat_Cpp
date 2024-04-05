#include "Game.h"

void Game::initVariables()
{
    this->stage = 0;
    this->idForPlayer = 0;
    this->me = Player("STARTING_GAME", -1);
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

        }
    }
}

void Game::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
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
    idForPlayer++;
    this->stage++;
    table.setStage(stage);
    table.initVariables();
}

void Game::update()
{
    this->pollEvents();
    this->updateMousePositions();
    if (this->stage == 0) {
        this->updateLoginScreen();
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
    Player p;
    float posX = 0;
    float posY = 0;
    for (const auto& player : table.getPlayers()) {
        for (const auto& card : player.getCards()) {
            if (card.isVisibleForAll()) {
                if (texture.loadFromFile(card.getFileName())) {
                    sf::Sprite sprite(texture);
                    sprite.setPosition(posX, posY);
                    sprite.setScale(0.2f, 0.2f);
                    this->window->draw(sprite);
                    posX += 100;
                }
            }
            else {
                if (texture.loadFromFile("img/back.png")) {
                    sf::Sprite sprite(texture);
                    sprite.setPosition(posX, posY);
                    sprite.setScale(0.2f, 0.2f);

                    this->window->draw(sprite);
                    posX += 100;
                }

            }
        }
        posX = 0;
        posY += 150;
    }
}

void Game::render()
{
    this->window->clear(sf::Color(0, 128, 43));
    if (stage == 0) {
        this->renderLoginScreen();
    }
    else if (stage == 1) {
        this->renderPlayerCards();
    }
    this->window->display();
}
