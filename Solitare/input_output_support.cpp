#include "input_output_support.h"
#include <iostream>

void Input_output_support::Present_actions() const
{
	std::cout << std::endl << std::endl;
	std::cout << "__[_Pasjans_]__" << std::endl;
	std::cout << "Choose option:" << std::endl;
	std::cout << "0- Exit " << std::endl;
	std::cout << "1- Select stacks " << std::endl;
	std::cout << "2- flip_choose_stack " << std::endl;
	std::cout << "9- Help " << std::endl;
	std::cout << "324-/-123" << std::endl;
}

std::vector<int> Input_output_support::Select_stacks()
{
	std::vector<int> input_val;

	std::cout << "--------| From: " << std::endl;

	std::cout << "0- Back to menu" << std::endl;

	std::cout << "8- Take card from finish_stack " << std::endl;
	std::cout << "9- Take card from choose_stack " << std::endl;
	for (int i = 0; i < 7; i++)
	{
		std::cout << i + 1 << "- Select " << i + 1 << " stack " << std::endl;
	}
	int card_from;
	std::cin >> card_from;
	std::cout << in_range(card_from, 1, 9);
	if (in_range(card_from, 1, 9))
	{
		if (card_from == 8) //Finish Stack
		{
			input_val.push_back(card_from);
			for (int j = 0; j < 4; j++)
			{
				std::cout << j + 1 << "- Select " << j + 1 << " Finish_stack " << std::endl;
			}
			int finish_index;
			std::cin >> finish_index;
			finish_index--;
			if (!in_range(finish_index, 0, 3))
			{
				std::cout << " Error Value ";
				input_val.clear();
				return input_val;
			}
			input_val.push_back(finish_index);
		}
		else if (card_from <= 7) //Card_stack
		{
			card_from--;
			input_val.push_back(card_from);
		}
		else //Coose Stack
		{
			input_val.push_back(card_from);
		}
		std::cout << "--------| To: " << std::endl;
		int card_to;
		std::cout << "0- Back to menu" << std::endl;
		if (card_from != 9)
		{
			std::cout << "8- Put card in finish_stack " << std::endl;
		}
		for (int i = 0; i < 7; i++)
		{
			std::cout << i + 1 << "- Select " << i + 1 << " stack " << std::endl;
		}
		std::cin >> card_to;
		if (in_range(card_to, 1, 8) && card_from != card_to)
		{
			if (card_to <= 7)
			{
				card_to--;
				input_val.push_back(card_to);
				std::cout << card_to << "card_to";
				if (card_from <= 6)
				{
					int n;
					std::cout << "1-jedna czy 2-wiecej? ";
					std::cin >> n;
					if (n == 2)
					{
						int name_card;
						//std::cout << "Podaj wartosc karty ze stosu 1";
						std::cout << "Podaj index karty ze stosu 1";
						std::cin >> name_card;
						input_val.push_back(name_card);
					}
				}
			}
			else
			{
				input_val.push_back(card_to);
			}
		return input_val;
		}
	}
	std::cout << " Error Value ";
	input_val.clear();
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
	case 123:
		return Game_event::test;
	case 324:
		return Game_event::debug_board;

	default:
		return Accept_input();
	}
	return Game_event();
}

bool Input_output_support::in_range(int a, int low, int high)
{
	if (a < low || a > high)
	{
		return false;
	}
	return true;
}
