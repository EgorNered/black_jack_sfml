#pragma once

#include "card.h"
#include <vector>
#include <utility>

class Deck {

	const int deck_size = 52;
	std::vector<std::pair<CardSuits, CardRank>> m_deck;
    const sf::Texture* m_texture;
    
public:
    Deck();
    
    void setTexture(const sf::Texture& texture);
    
	void shuffle();//перетасовать колоду
    
    Card pop();
};
