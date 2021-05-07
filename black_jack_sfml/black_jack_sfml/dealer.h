#pragma once

#include "hand.h"

class Dealer: public Hand {
public:
	void update(GameState& state) override;
};
