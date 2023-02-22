#include "cards_stack.h"
#include <iostream>

/*/Cards_stack::Cards_stack()
{
	int quantity_stack = 6;
	bool face_up = true;
	for (int column = 1; column <= 6; column++)
	{

	}
	face_down = false;
}/*/

Cards_stack::Cards_stack(int number_of_stack, Deck deck_val)
{
	bool face_option = true;
	for (int i = 1; i < number_of_stack; i++)
	{
		Create_stack(deck_val.Draw(), face_option);
	}
}

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

void Cards_stack::Add_card(Card card_val)
{

}

