#pragma once
#include "game_event.h"

class Input_output_support
{
public:
	void Present_actions() const;
	void Help_Guide() const;
	Game_event Accept_input() const;
};
