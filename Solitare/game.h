#pragma once
#include "cards_stack.h"
#include "finish_stack.h"
#include "choose_stack.h"
#include "game_event.h"



class Game: public I_printable
{
public:
	Game();

	void Set_location();

	// I_printable
	virtual void Show_debug() const override;
	virtual void Show_user() const override;
	
	void Show_user_option();
	Game_event Choose_action();
private:
	// Player movements
	void Shuffle_cards();
	void Handle_event(int option);
	void Move_cards(std::vector<int> input_val);


	//Game board - stack
	Deck m_deck;
	std::vector<Cards_stack> m_columns;
	std::vector<Finish_stack> m_finish_stacks;
	Choose_stack m_choose_card;

	//active position, event, selected_card
	enum class Location
	{
		hidden_choose_stack,
		choose_stack,
		finish_stack,
		stack,
	};

	Location active_location = Location::hidden_choose_stack;

	enum class Action
	{
		nothing,
		selected_stack,
		card_flip_hidden_choose_stack,
		card_from_choose_stack,
		card_from_stack,
		card_to_stack,
		card_from_finish_stack,
		card_to_finish_stack
	};

	int selected_column = 0;
	int selected_row = 0;

	int Select_more_cards();
	Action Available_move();

	std::vector<int> selected_cards;
	void Uncheck_all_cards();
};