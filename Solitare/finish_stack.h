#pragma once
#include <vector>
#include "card.h"

class Finish_stack
{
public:
	bool Add_card(Card);
private:
	std::vector<Card> m_card;
};