#include "cards_stack.h"


Cards_stack::Cards_stack(int number_of_stack, Deck &deck_val)
{
	for (int i = 0; i < number_of_stack; i++)
	{
		face_down.push_back(deck_val.Draw());
	}
	face_up.push_back(deck_val.Draw());
	//face_up.back().SetSelect(true);
}

Card Cards_stack::Give_card(int index)
{
	return face_up.at(face_up.size() - 1 - index);
}

bool Cards_stack::Check_not_empty()
{
	if (!face_up.empty())
	{
		return true;
	}
	return false;
}

void Cards_stack::Add_card(Card card_val)
{
	face_up.push_back(card_val);
}

void Cards_stack::Remove_card(int quantity, int index)
{
	for (int i = index; i < quantity; i++)
	{
		face_up.pop_back();
	}
	if (!face_down.empty() and face_up.empty())
	{
		face_up.push_back(face_down.back());
		face_down.pop_back();
	}
}

bool Cards_stack::Check_take_card(const Card& card_to_check) const
{
	return true;
	if (card_to_check.GetValue() == face_up.back().GetValue() + 1
		&& int(card_to_check.GetColour())%2 == int(face_up.back().GetColour())%2)
	{
		return true;
	}
	return false;
}

bool Cards_stack::Check_has_card(int card_value) const
{
	for (int i = 0; i < face_up.size(); i++)
	{
		if (face_up.at(i).GetValue() == card_value)
		{
			return true;
		}
	}
	return false;
}

int Cards_stack::Give_index(int card_value)
{
	for (int i = 0; i < face_up.size(); i++)
	{
		if (face_up.at(i).GetValue() == card_value)
		{
			return i;
		}
	}
	return 55555;
}

int Cards_stack::Size_face_up()
{
	return face_up.size();
}

void Cards_stack::SetSelect_card(bool option, int index)
{
	face_up.at(face_up.size() - 1 - index).SetSelect(option);
}

void Cards_stack::Show_card(int index) const
{
	if (face_down.size() + face_up.size() <= index)
	{
		std::cout << "        ";
	}
	else if (face_down.size() > index)
	{
		std::cout << " [ X.X ]";
	}
	else
	{
		//face_up.at(index - face_down.size()).m_selected = true;
		face_up.at(index - face_down.size()).Show_user();
	}
}


void Cards_stack::Show_debug() const
{
	for (int i = 0; i < face_down.size(); i++)
	{
		face_down[i].Show_debug();
	}
	std::cout << "|";
	for (int i = 0; i < face_up.size(); i++)
	{
		face_up[i].Show_debug();
		
	}
}

