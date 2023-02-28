#include "choose_stack.h"

Choose_stack::Choose_stack(Deck& deck_val)
{
	while (!deck_val.Is_empty())
	{
		m_hidden_cards.push_back(deck_val.Draw());
	}
}


void Choose_stack::Show_choose_stack()
{
	for (int i = 0; i < m_visible_cards.size(); i++)
	{
		std::cout << "[" << m_visible_cards[i].m_value << "." << (int)m_visible_cards[i].m_colour << "] ";
	}
	for (int i = 0; i < m_hidden_cards.size(); i++)
	{
		std::cout << "[" << m_hidden_cards[i].m_value << "." << (int)m_hidden_cards[i].m_colour << "] ";
	}
}

bool Choose_stack::Check_take_card(Card card_to_check)
{
	if (card_to_check.m_value  == m_visible_cards.back().m_value + 1
		&& card_to_check.m_colour == m_visible_cards.back().m_colour)
	{
		return true;
	}

	return false;
}

Card Choose_stack::Take_card(Card card_to_take)
{
	m_visible_cards.erase(m_visible_cards.begin() + m_visible_cards.size());
	return card_to_take;
	//[-] Task: accept card in execute function - first check with Check_take_card function!
	
	 //type :thonk: something is wrong. 
				//Maybe type should be Card - return Card if true, 
				//but what should I do if false? :thonk: 
					//-> function to chceck this problem (?)
}

bool Choose_stack::See_card()
{
	if (m_visible_cards.size() == 1)
	{
		if (m_hidden_cards.size() == 0)
		{
			return true;
		}
		else
		{
			m_hidden_cards.insert(m_hidden_cards.end(), m_visible_cards.begin(), m_visible_cards.end());
			m_visible_cards.erase(m_visible_cards.begin());
			m_visible_cards.swap(m_hidden_cards);
		}
	}
	else if (m_visible_cards.size() > 1)
	{
		m_hidden_cards.insert(m_hidden_cards.end(), m_visible_cards.begin(), m_visible_cards.begin() + 1);
		m_visible_cards.erase(m_visible_cards.begin());
	}
	return false;
}

void Choose_stack::Insert_cards(const std::vector<Card>& cards)
{
	//m_visible_cards.insert(cards.begin(), cards.end());
}
