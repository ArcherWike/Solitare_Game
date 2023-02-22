#pragma once
#include "deck.h"

class Choose_stack
{
public:
	bool Take_card(Card card_to_check);
	bool See_card();
	void Insert_cards(const std::vector<Card>& cards);
private:
	std::vector<Card> m_hidden_cards;
	std::vector<Card> m_visible_cards;
};