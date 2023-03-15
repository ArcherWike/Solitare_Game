#pragma once
#include <vector>
#include "card.h"
#include "printable.h"

class Finish_stack: public I_printable
{
public:
	bool Add_card(Card card_to_add);
	// Odziedziczono za po�rednictwem elementu I_printable
	virtual void Show_debug() const override;
private:
	std::vector<Card> m_card;

};