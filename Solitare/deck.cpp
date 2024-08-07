#include "deck.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Deck::Deck()
{
	for (int i = 1; i <= 13; i++)
	{
		for (int j = (int)Card::Colour::clubs; j <= (int)Card::Colour::spades; j++)
		{
			m_cards.push_back(Card(i, (Card::Colour)j));
			//std::cout << i << " " << (int)(Card::Colour)j << std::endl;
		}
	}
}

Card Deck::Draw()
{
	srand(time(NULL));
	int card_index = rand() % m_cards.size();
	Card pulled = m_cards[card_index];
	m_cards.erase(m_cards.begin() + card_index);
	return pulled;
}

bool Deck::Is_empty() const
{
	return m_cards.empty();
}

std::vector<Card> Deck::Transfer_all_cards()
{
	return m_cards;
}

