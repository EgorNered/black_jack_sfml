#include "player.h"
#include "game.h"

void Player::update(GameState& state) {
    if (state.resieveInput) {
        switch (state.userInput) {
            case sf::Keyboard::Y:
                state.resieveInput = false;
                takeOneCard(state.deck.pop());
                break;
            case sf::Keyboard::N:
                state.resieveInput = false;
                m_status = GAME_PASS;
                break;
            default:
                ;
        }
        state.userInput = 0;
    } else if (m_status == GAME_CONTINUE) {
        m_status = GAME_WAIT;
        state.resieveInput = true;
    }
}
