#pragma once

#include <SFML/Graphics.hpp>

enum CardSuits {
    CARD_DIAMONDS,//бубны
    CARD_HEARTS,//черви
    CARD_SPADES,//пики
    CARD_CLUBS,//крести
    MAX_SUITS//конец перечисления
};

enum CardRank {
    CARD_A,//0
    CARD_2,//1
    CARD_3,//2
    CARD_4,//3
    CARD_5,//4
    CARD_6,//5
    CARD_7,//6
    CARD_8,//7
    CARD_9,//8
    CARD_10,//9
    CARD_J,//10
    CARD_Q,//11
    CARD_K,//12
    MAX_RANK//конец перечисления
};

class Card : public sf::Drawable, public sf::Transformable
{
public:
    Card(const sf::Texture* texture, CardRank rank, CardSuits suit);

    int get_score() const;
    
    CardRank get_rank() const;
    
    CardSuits get_suit() const;

    static float getWidth();
    
    static float getHeight();

private:
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    CardRank m_rank;
    CardSuits m_suit;

    static int cardWidth;
    static int cardHeight;

    sf::Sprite cardSprite;
};
