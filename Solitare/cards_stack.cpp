#include "cards_stack.h"

Cards_stack::Cards_stack(int number_of_stack, Deck &deck_val)
{
	for (int i = 0; i < number_of_stack; i++)
	{
		face_down.push_back(deck_val.Draw());
	}
	face_up.push_back(deck_val.Draw());
}
void Cards_stack::Show_cards_stack()
{
	for (int i = 0; i < face_up.size(); i++)
	{
		std::cout << "[" << face_up[i].m_value << "." << (int)face_up[i].m_colour << "] ";
	}
	for (int i = 0; i < face_down.size(); i++)
	{
		std::cout << "[" << face_down[i].m_value << "." << (int)face_down[i].m_colour << "] ";
	}
}
/*/
void Cards_stack::Create_stack(Card card_val, bool face_option)
{
	if (face_option)
	{
		face_up.push_back(card_val);
	}
	else
	{
		face_down.push_back(card_val);
	}

}
/*/
void Cards_stack::Add_card(Card card_val)
{

}

