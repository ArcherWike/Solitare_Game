#pragma once
#include "cards_stack.h"
#include "finish_stack.h"
#include "choose_stack.h"
#include "game_event.h"


class Game
{
public:
	Game();
	void Handle_event(Game_event action);
	
private:
	void Shuffle_cards();
	Deck m_deck;
	std::vector<Cards_stack> m_columns;

	std::vector<Finish_stack> m_finish_stacks;

	Choose_stack m_choose_card;
};