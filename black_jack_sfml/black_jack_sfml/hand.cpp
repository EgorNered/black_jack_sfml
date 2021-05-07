#include "hand.h"
#include "card.h"
#include "game.h"

Hand::Hand() : m_status(GAME_CONTINUE), m_score(0) {
}

void  Hand::takeOneCard(Card card) {
    if (!m_hand.empty()) {
        card.setPosition(m_hand.back().getPosition() + sf::Vector2f(card.getWidth(), 0));
    }
    
	m_hand.push_back(card);
    calculateScore();
    if (m_score < 21)
        m_status = GAME_CONTINUE;
    else if (m_score == 21)
        m_status = GAME_WIN;
    else
        m_status = GAME_LOSE;
}

void Hand::clear() {
    m_status = GAME_CONTINUE;
    m_score = 0;
    m_hand.clear();
}

Hand::GameStatus Hand::getStatus() const {
    return m_status;
}

int Hand::getScore() const {
    return m_score;
}

void Hand::calculateScore() {
	int size = m_hand.size();
	m_score = 0;
	for (int i = 0; i < size; i++) {
		//если карта туз - то
		//попробовать добавить 10
		if (m_hand[i].get_rank() == CARD_A) {
			m_score = m_score + 10 + m_hand[i].get_score();
			if (m_score > 21) m_score = m_score - 10;
		}
		//иначе просто добавить к счету очки карты
		else
			m_score = m_score + m_hand[i].get_score();
	}
}

void Hand::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	//проход по руке
	int size = m_hand.size();
	for (int i = 0; i < size; i++) {
		//сместиться в новые координты в окне
		target.draw(m_hand[i], states);
	}
}
