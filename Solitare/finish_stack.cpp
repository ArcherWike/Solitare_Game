#include "finish_stack.h"
#include <iostream>

void Finish_stack::Show_finish_stack()
{
	for (int i = 0; i < m_card.size(); i++)
	{
		std::cout << "[" << m_card[i].m_value << "." << (int)m_card[i].m_colour << "] ";
	}
}

bool Finish_stack::Add_card(Card card_to_add)
{
	if (m_card.empty())
	{
		m_card.push_back(card_to_add);
		return true; //[-] Task: take card from execute function
	}
	else if (m_card.back().m_value + 1 == card_to_add.m_value 
		  && m_card.back().m_colour == card_to_add.m_colour)
	{
		m_card.push_back(card_to_add);
		return true; //[-] Task: take card from execute function
	}
	return false;
}
