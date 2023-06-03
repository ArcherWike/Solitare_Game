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


void Input_output_support::Help_Guide() const
{
	std::cout << " I can't help you yet..." << std::endl;
}

