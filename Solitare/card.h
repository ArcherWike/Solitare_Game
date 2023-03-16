#pragma once

class Card
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

//private:
	int m_value;
	Colour m_colour;
};