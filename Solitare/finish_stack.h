#pragma once
#include <vector>
#include "card.h"

class Finish_stack
{
public:
	bool Add_card(Card card_to_add);
private:
	std::vector<Card> m_card;
};