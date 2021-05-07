#include "game.h"
#include <iostream>

Game::Game() : m_stage(Stage::NEW_GAME) {
    m_player.move(0.0f, Card::getHeight() + 50.0f);
    m_texture.loadFromFile("D:\images/deck.png");
    m_state.deck.setTexture(m_texture);
    m_state.resieveInput = false;
    m_state.userInput = 0;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_dealer, states);
    target.draw(m_player, states);
}

void Game::processInput(sf::Uint32 keyCode) {
    if (m_state.resieveInput)
        m_state.userInput = keyCode;
}

void Game::update() {
    switch (m_stage) {
        case Stage::NEW_GAME:
            newGame();
            break;
        case Stage::FINISHED:
            gameFinished();
            break;
        case Stage::PLAYER_TURN:
            playerTurn();
            break;
        case Stage::DEALER_TURN:
            dealerTurn();
            break;
        default:
            ;
    }
}

bool Game::isRunning() const {
    return m_stage != Stage::TERMINATE;
}


void Game::newGame() {
    m_state.deck.shuffle();
    
    m_dealer.clear();
    m_dealer.takeOneCard(m_state.deck.pop());
    m_dealer.takeOneCard(m_state.deck.pop());
    
    m_player.clear();
    m_player.takeOneCard(m_state.deck.pop());
    m_player.takeOneCard(m_state.deck.pop());
    
    m_stage = Stage::PLAYER_TURN;
}

void Game::gameFinished() {
    if (m_state.resieveInput) {
        switch (m_state.userInput) {
            case sf::Keyboard::Y:
                m_state.resieveInput = false;
                std::cout << "Starting new game" << std::endl;
                m_stage = Stage::NEW_GAME;
                break;
            case sf::Keyboard::N:
                m_state.resieveInput = false;
                m_stage = Stage::TERMINATE;
                break;
            default:
                ;
        }
        m_state.userInput = 0;
    } else {
        std::cout << "Restart? (y/n)" << std::endl;
        m_state.resieveInput = true;
    }
}

void Game::playerTurn() {
    switch (m_player.getStatus()) {
        case Hand::GAME_CONTINUE:
            std::cout << "Your score: " << m_player.getScore()
                      << " More? (y/n)" << std::endl;
            break;
        case Hand::GAME_LOSE:
            std::cout << "Your score: " << m_player.getScore()
                      << " You lose!" << std::endl;
            m_stage = Stage::FINISHED;
            break;
        case Hand::GAME_WIN:
            std::cout << "Your score: 21 You won!" << std::endl;
            m_stage = Stage::FINISHED;
            break;
        case Hand::GAME_PASS:
            m_stage = Stage::DEALER_TURN;
            break;
        default:
            ;
    }
    m_player.update(m_state);
}

void Game::dealerTurn() {
    switch (m_dealer.getStatus()) {
        case Hand::GAME_LOSE:
            std::cout << "Dealer score: " << m_dealer.getScore()
                      << " You won!" << std::endl;
            m_stage = Stage::FINISHED;
            break;
        case Hand::GAME_WIN:
            std::cout << "Dealer won! Score: 21" << std::endl;
            m_stage = Stage::FINISHED;
            break;
        case Hand::GAME_PASS:
            std::cout << "Dealer score: " << m_dealer.getScore() << std::endl;
            if (m_dealer.getScore() < m_player.getScore())
                    std::cout << "You won!" << std::endl;
            else if (m_dealer.getScore() == m_player.getScore())
                    std::cout << "Draw!" << std::endl;
            else
                std::cout << "Dealer won!" << std::endl;
            m_stage = Stage::FINISHED;
            break;
        default:
            ;
    }
    m_dealer.update(m_state);
}
