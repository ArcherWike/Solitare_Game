#include "input_output_support.h"
#include <iostream>


void Input_output_support::Present_actions() const
{
	std::cout << "__[_Pasjans_]__" << std::endl;
	std::cout << "Choose option:" << std::endl;
	std::cout << "0- Exit " << std::endl;
	std::cout << "9- Help " << std::endl;
	std::cout << "1- Show card from choose_stack " << std::endl;
	std::cout << "2- Take card from choose_stack " << std::endl;
	std::cout << "3- Take card from finish_stack " << std::endl;
	for (int i = 1; i <= 7; i++)
	{
		std::cout << i + 3 << "- Select " << i << " stack " << std::endl;
	}
	std::cout << "324-" << std::endl;
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
