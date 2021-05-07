#include "dealer.h"
#include "game.h"

void Dealer::update(GameState& state) {
    
    if (getScore() < 17)
        takeOneCard(state.deck.pop());
    else if (m_status == GAME_CONTINUE)
        m_status = GAME_PASS;
}
