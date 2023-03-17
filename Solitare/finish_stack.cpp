#include "finish_stack.h"
#include <iostream>

bool Finish_stack::Check_take_card(Card card_to_check)
{
	if (m_card.empty())
	{
		//if (card_to_check.m_value == 0)
		return true;
	}
	else if (m_card.back().m_value + 1 == card_to_check.m_value
		&& m_card.back().m_colour == card_to_check.m_colour)
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

void Finish_stack::Show_debug() const
{
	for (int i = 0; i < m_card.size(); i++)
	{
		std::cout << "[" << m_card[i].m_value << "." << (int)m_card[i].m_colour << "] ";
	}
}
