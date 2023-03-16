#pragma once
#include <vector>
#include "card.h"
#include <iostream>

class Deck
{
public:
	Deck();
	Card Draw();
	bool Is_empty() const;
	std::vector<Card> Transfer_all_cards();
	//void Transfer_choose_stack(Choose_stack object, std::vector<Card> cards);
private:
	std::vector<Card> m_cards;
};