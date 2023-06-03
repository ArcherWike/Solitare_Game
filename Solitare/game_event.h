#pragma once

enum class Game_event
{
	help, //
	exit,
	debug_board, //
	select,
	move,

	hidden_choose_stack,
	choose_stack,
	finish_stack,
	stack,

	//possible moves
	nothing,
	selected_stack,
	card_from_choose_stack,

	card_from_stack,
	card_to_stack,

	card_from_finish_stack,
	card_to_finish_stack,






	test //
};