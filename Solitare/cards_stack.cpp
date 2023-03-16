#include "cards_stack.h"


Cards_stack::Cards_stack(int number_of_stack, Deck &deck_val)
{
	for (int i = 0; i < number_of_stack; i++)
	{
		face_down.push_back(deck_val.Draw());
	}
	face_up.push_back(deck_val.Draw());
}

Card Cards_stack::Give_card(int index)
{
	return face_up.at(0);
}

void Cards_stack::Add_card(Card card_val)
{
	face_up.push_back(card_val);
}

bool Cards_stack::Check_take_card(Card card_to_check)
{
	if (card_to_check.m_value == face_up.front().m_value + 1)
		//&& card_to_check.m_colour == face_up.back().m_colour)
	{
		return true;
	}
	return false;
}

void Cards_stack::Show_debug() const
{
	for (int i = 0; i < face_down.size(); i++)
	{
		std::cout << "[" << face_down[i].m_value << "." << (int)face_down[i].m_colour << "] ";
	}
	std::cout << "|";
	for (int i = 0; i < face_up.size(); i++)
	{
		std::cout << "[" << face_up[i].m_value << "." << (int)face_up[i].m_colour << "] ";
		
	}
}

