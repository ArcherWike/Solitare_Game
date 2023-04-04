#pragma once
#include "cards_stack.h"
#include "finish_stack.h"
#include "choose_stack.h"
#include "game_event.h"



class Game: public I_printable
{
public:
	Game();
	void Handle_event(Game_event action);
	void Move_cards(std::vector<int> input_val);
	
	// Odziedziczono za poœrednictwem elementu I_printable
	virtual void Show_debug() const override;
	virtual void Show_user() const override;
private:
	void Shuffle_cards();
	Deck m_deck;
	std::vector<Cards_stack> m_columns;

	std::vector<Finish_stack> m_finish_stacks;

	Choose_stack m_choose_card;

};