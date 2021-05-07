#pragma once

#include "player.h"
#include "dealer.h"
#include "deck.h"
#include <SFML/Graphics.hpp>

class GameState
{
public:
    Deck deck;
    bool resieveInput;
    sf::Uint32 userInput;
};

class Game : public sf::Drawable, public sf::Transformable {

public: 
	Game();

    void processInput(sf::Uint32 keyCode);
    
    void update();
    
    bool isRunning() const;
    
private:
    
    enum Stage {
        NEW_GAME,
        FINISHED,
        PLAYER_TURN,
        DEALER_TURN,
        TERMINATE
    };
    
    void newGame();
    
    void gameFinished();
    
    void playerTurn();
    
    void dealerTurn();
    
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
    
    sf::Texture m_texture;
	Dealer m_dealer;
    Player m_player;
    GameState m_state;
    Stage m_stage;
};
