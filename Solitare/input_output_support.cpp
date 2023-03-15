#include "input_output_support.h"
#include <iostream>



void Input_output_support::Present_actions() const
{
	std::cout << std::endl << std::endl;
	std::cout << "__[_Pasjans_]__" << std::endl;
	std::cout << "Choose option:" << std::endl;
	std::cout << "0- Exit " << std::endl;
	std::cout << "2- flip_choose_stack " << std::endl;
	std::cout << "9- Help " << std::endl;
	std::cout << "1- Select stacks " << std::endl;
	std::cout << "324-" << std::endl;
}

std::vector<int> Input_output_support::Select_stacks()
{
	std::cout << "From: " << std::endl; 
	std::cout << "1- Take card from choose_stack " << std::endl;
	//std::cout << "2- Take card from finish_stack " << std::endl;
	for (int i = 0; i < 7; i++)
	{
		std::cout << i + 3 << "- Select " << i+1 << " stack " << std::endl;
	}
	int card_from;
	std::cin >> card_from;

	Game_event d = static_cast<Game_event>(card_from);
	if (d == Game_event::move) {
		std::cout << "move";
	}
	else if (d == Game_event::debug_board) {
		std::cout << "debug";
	}
	else {
		std::cout << "non";
	}

	std::cout << "To: " << std::endl;
	//std::cout << "2- Put card in finish_stack " << std::endl;
	for (int i = 0; i < 7; i++)
	{
		std::cout << i + 3 << "- Select " << i+1 << " stack " << std::endl;
	}
	int card_to;
	std::cin >> card_to;
	
	if (card_from == card_to)
	{
		return Select_stacks();
	}
	

	std::vector<int> input_val;
	input_val.push_back(card_from);
	input_val.push_back(card_to);
	
	return input_val;
}

void Input_output_support::Help_Guide() const
{
	std::cout << " I can't help you yet..." << std::endl;
}

Game_event Input_output_support::Accept_input() const
{
	Present_actions();
	int user_button;
	std::cin >> user_button;
	switch (user_button)
	{
	case 0:
		return Game_event::exit;
	case 1:
		return Game_event::move;
	case 2:
		return Game_event::flip_choose_stack;
	case 9:
		Help_Guide();
		return Accept_input();
	case 324:
		return Game_event::debug_board;

	default:
		Present_actions();
		return Accept_input();
	}
	return Game_event();
}
