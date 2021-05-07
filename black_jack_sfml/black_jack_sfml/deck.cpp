#include "deck.h"
#include <random>
#include <algorithm>

Deck::Deck() : m_texture(nullptr) {
    shuffle();
}

void Deck::setTexture(const sf::Texture& texture) {
    m_texture = &texture;
}

void Deck::shuffle() {
    m_deck.clear();
    for (int j = 0; j < MAX_SUITS; j++) {
        for (int k = 0; k < MAX_RANK; k++) {
            //создать карту и добавить её в вектор
            m_deck.push_back(std::make_pair(static_cast<CardSuits>(j), static_cast<CardRank>(k)));
        }
    }
    std::mt19937 rnd(std::random_device{}());
    std::shuffle(m_deck.begin(), m_deck.end(), rnd);
}

Card Deck::pop() {
    auto card = m_deck.back();
    m_deck.pop_back();
    return Card(m_texture, card.second, card.first);
}
