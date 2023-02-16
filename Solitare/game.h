#pragma once
#include "deck.h"
#include "cards_stack.h"

class Game
{
	Game();
private:
	Deck m_deck;

	std::vector<Cards_stack> columns;
};