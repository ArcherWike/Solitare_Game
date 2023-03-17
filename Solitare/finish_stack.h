#pragma once
#include <vector>
#include "card.h"
#include "printable.h"

class Finish_stack: public I_printable
{
public:
	bool Check_take_card(Card card_to_check);
	void Add_card(Card card_to_add);
	Card Give_card();
	void Remove_card();
	bool Check_not_empty();
	// Odziedziczono za poœrednictwem elementu I_printable
	virtual void Show_debug() const override;
private:
	std::vector<Card> m_card;

};