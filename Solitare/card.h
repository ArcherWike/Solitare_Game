#pragma once
#include "printable.h"
#include <string>

class Card: public I_printable
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
	virtual void Show_debug() const override;
	virtual void Show_user() const override;

	int m_value;
	Colour m_colour;
private:
	static std::string ColourToString(const Colour& val_colour);
	static char ColourToSign(const Colour& val_colour);

	static std::string ValueToString(const int& val);
};