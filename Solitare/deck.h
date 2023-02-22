#pragma once
#include <vector>
#include "card.h"
#include "choose_stack.h"

class Deck
{
public:
	Deck();
	Card Draw(); //
	void Transfer_choose_stack(Choose_stack object, std::vector<Card> cards);
private:
	std::vector<Card> m_cards;
};