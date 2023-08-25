#pragma once
#include "deck.h"
#include "printable.h"

class Choose_stack: public I_printable
{
public:
	Choose_stack(){}
	Choose_stack(Deck& deck_val);

	Card Give_card();
	void Remove_card();
	bool Check_not_empty();
	bool Check_hidden_stack_not_empty();
	bool See_card();

	void SetSelect_card(bool option);



	// Odziedziczono za poœrednictwem elementu I_printable
	virtual void Show_debug() const override;
	virtual void Show_user() const override;
private:
	std::vector<Card> m_hidden_cards;
	std::vector<Card> m_visible_cards;

};