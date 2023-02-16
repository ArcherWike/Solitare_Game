#pragma once
#include "card.h"
#include <vector>

class Cards_stack
{
public:
	void Add_card(Card card_val);
	bool Move_cards(const std::vector<Card>& cards);

private:
	std::vector<Card> face_down;
	std::vector<Card> face_up;
};