#pragma once
#include "deck.h"
#include <vector>
#include "printable.h"

class Cards_stack: public I_printable
{
public:
	Cards_stack(int number_of_stack, Deck &deck_val);
	
	Card Give_card(int index = 0);
	bool Check_not_empty();
	void Add_card(Card card_val);
	void Remove_card(int quantity = 1, int index = 0);
	bool Check_take_card(const Card& card_to_check) const;
	bool Check_has_card(int card_value) const;
	int Give_index(int card_value);
	int Size_face_up();

	void SetSelect_card(bool option, int index = 0);

	void Show_card(int index) const;
	// Odziedziczono za poœrednictwem elementu I_printable
	virtual void Show_debug() const override;
private:
	std::vector<Card> face_down;
	std::vector<Card> face_up;
};