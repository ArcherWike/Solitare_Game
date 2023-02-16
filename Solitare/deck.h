#pragma once
#include <vector>
#include "card.h"


class Deck
{
public:
	Deck();
	Card Draw();
private:
	std::vector<Card> m_cards;
};