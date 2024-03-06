#include "finish_stack.h"
#include <iostream>

bool Finish_stack::Check_take_card(const Card& card_to_check) const
{
	if (m_card.empty())
	{
		if (card_to_check.GetValue() == 1)
		{
			return true;

		}
	}
	else if (m_card.back().GetValue() + 1 == card_to_check.GetValue()
		&& m_card.back().GetColour() == card_to_check.GetColour())
	{
		return true; 
	}
	return false;
}

void Finish_stack::Add_card(Card card_to_add)
{
	m_card.push_back(card_to_add);//[-] Task: take card from execute function
}

Card Finish_stack::Give_card()
{
	return m_card.front();
}

void Finish_stack::Remove_card()
{
	m_card.pop_back();
}

bool Finish_stack::Check_not_empty()
{
	if (m_card.empty())
	{
		return false;
	}
	return true;
}

void Finish_stack::SetSelect_card(bool option)
{
	m_card.back().SetSelect(option);
}

void Finish_stack::Show_debug() const
{
	for (int i = 0; i < m_card.size(); i++)
	{
		m_card[i].Show_debug();
	}
}

void Finish_stack::Show_user() const
{
	if (!m_card.empty())
	{
		//m_card.back().SetSelect(true);
		m_card.back().Show_user();
	}
	else
	{
		std::cout << "[     ]";
	}
}
