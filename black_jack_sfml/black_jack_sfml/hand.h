#pragma once

#include "card.h"
#include <SFML/Graphics.hpp>
#include <vector>

class GameState;

class Hand : public sf::Drawable, public sf::Transformable {
  
public:
    
	enum GameStatus {
        GAME_WAIT,
		GAME_CONTINUE,
		GAME_WIN,
		GAME_LOSE,
        GAME_PASS,
		MAX_STATUS
	};
    
    Hand();
    
    void takeOneCard(Card card);
    
    void clear();
    
	int getScore() const;
    
    GameStatus getStatus() const;
    
    virtual void update(GameState& state) = 0;

protected:
    
    GameStatus m_status;
    
private:
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    void calculateScore();
    
	std::vector<Card> m_hand;
    int m_score;
};
