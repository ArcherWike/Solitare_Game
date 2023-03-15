#pragma once
#include "printable.h"

class Card : public I_printable
{
public:
	enum class Colour
	{
		clubs,
		diamonds,
		hearts,
		spades
	};
	Card(int val, Colour val_colour);
	// Odziedziczono za poœrednictwem elementu I_printable
	virtual void Show_debug() const override;
//private:
	int m_value;
	Colour m_colour;

};