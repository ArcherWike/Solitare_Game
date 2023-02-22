#pragma once
#include "cards_stack.h"
#include "finish_stack.h"


class Game
{
public:
	Game();
	void Shuffle_cards();
	
private:
	Deck m_deck;
	std::vector<Cards_stack> columns;
};