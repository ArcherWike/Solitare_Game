#pragma once
#include "game_event.h"
#include <vector>

class Input_output_support
{
public:
	void Present_actions() const;
	std::vector<int> Select_stacks();
	void Help_Guide() const;
	Game_event Accept_input() const;
};
