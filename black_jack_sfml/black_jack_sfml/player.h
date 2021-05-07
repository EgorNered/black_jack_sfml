#pragma once
#include "hand.h"

class Player : public Hand {
public:
	void update(GameState& state) override;
};
