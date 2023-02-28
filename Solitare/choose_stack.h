#pragma once
#include "deck.h"

class Choose_stack
{
public:
	Choose_stack(){}
	Choose_stack(Deck& deck_val);
	void Show_choose_stack();
	bool Check_take_card(Card card_to_check);
	Card Take_card(Card card_to_take);
	bool See_card();
	void Insert_cards(const std::vector<Card>& cards);
	void Collect_from_deck();//(?)
private:
	std::vector<Card> m_hidden_cards;
	std::vector<Card> m_visible_cards;
};