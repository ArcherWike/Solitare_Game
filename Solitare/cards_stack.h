#pragma once
#include "deck.h"
#include <vector>

class Cards_stack
{
public:
	Cards_stack(int number_of_stack, Deck &deck_val);
	void Show_cards_stack();
	//void Create_stack(Card card_val, bool face_option); //
	void Add_card(Card card_val);
	bool Move_cards(const std::vector<Card>& cards);
private:
	std::vector<Card> face_down;
	std::vector<Card> face_up;
};