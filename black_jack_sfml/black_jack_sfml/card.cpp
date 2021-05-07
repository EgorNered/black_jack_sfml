#include "card.h"
#include <SFML/Graphics.hpp>

int Card::cardWidth = 72;
int Card::cardHeight = 97;

Card::Card(const sf::Texture* texture, CardRank rank, CardSuits suit) {
    
	m_rank = rank;
	m_suit = suit;
    
    if (texture) {
        cardSprite.setTexture(*texture);
    }
    
	int textureX = 1 + (cardWidth + 1) * m_rank,
        textureY = 1;
        
	if (m_suit == CARD_HEARTS)
        textureY += cardHeight + 1;
	else if (m_suit == CARD_DIAMONDS)
        textureY += (cardHeight + 1) * 3;
	else if (m_suit == CARD_SPADES)
        textureY += (cardHeight + 1) * 2;

	cardSprite.setTextureRect(sf::IntRect(textureX, textureY, cardWidth, cardHeight));
}

void Card::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(cardSprite, states);
}

int Card::get_score() const {
    static int scores[MAX_RANK] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10
    };
    return scores[m_rank];
}

float Card::getWidth() {
     return static_cast<float>(cardWidth);
}

float Card::getHeight() {
    return static_cast<float>(cardHeight);
}

CardRank Card::get_rank() const {
	return m_rank;
}

CardSuits Card::get_suit() const {
	return m_suit;
}
