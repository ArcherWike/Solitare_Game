#pragma once
#include "deck.h"
#include <vector>
#include "printable.h"

class Cards_stack: public I_printable
{
public:
	Cards_stack(int number_of_stack, Deck &deck_val);
	
	Card Give_card(int index);
	void Add_card(Card card_val);
	bool Check_take_card(Card card_to_check);

	// Odziedziczono za poœrednictwem elementu I_printable
	virtual void Show_debug() const override;
private:
	std::vector<Card> face_down;
	std::vector<Card> face_up;
};