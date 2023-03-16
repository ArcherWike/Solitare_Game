#include "choose_stack.h"

Choose_stack::Choose_stack(Deck& deck_val)
{
	while (!deck_val.Is_empty())
	{
		m_hidden_cards.push_back(deck_val.Draw());
	}


}

Card Choose_stack::Give_card()
{
	return m_visible_cards.at(0);//front
}

void Choose_stack::Remove_card()
{
	m_visible_cards.pop_back();
}

bool Choose_stack::Check_not_empty()
{
	if (!m_visible_cards.empty())
	{
		return true;
	}
	return false;
}	//m_visible_cards.erase(m_visible_cards.begin() + m_visible_cards.size());


bool Choose_stack::See_card()
{
	if (m_hidden_cards.empty())
	{
		return true;
	}
	else if (m_visible_cards.empty())
	{
		m_visible_cards.insert(m_visible_cards.end(), m_hidden_cards.begin(), m_hidden_cards.begin() + 1);
		m_hidden_cards.erase(m_hidden_cards.begin());
	}
	else
	{
		m_hidden_cards.insert(m_hidden_cards.end(), m_visible_cards.begin(), m_visible_cards.begin() + 1);
		m_visible_cards.erase(m_visible_cards.begin());
		m_visible_cards.insert(m_visible_cards.end(), m_hidden_cards.begin(), m_hidden_cards.begin() + 1);
		m_hidden_cards.erase(m_hidden_cards.begin());
	}
	Show_debug();
	return false;
}

void Choose_stack::Show_debug() const
{
	std::cout << "visible: " << std::endl;
	for (int i = 0; i < m_visible_cards.size(); i++)
	{
		std::cout << "[" << m_visible_cards[i].m_value << "." << (int)m_visible_cards[i].m_colour << "] ";
	}
	std::cout << std::endl;
	std::cout << "hidden: " << std::endl;
	for (int i = 0; i < m_hidden_cards.size(); i++)
	{
		std::cout << "[" << m_hidden_cards[i].m_value << "." << (int)m_hidden_cards[i].m_colour << "] ";
	}
	std::cout << std::endl;
}
