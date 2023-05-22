#include "card.h"
#include <iostream>
#include <windows.h>
#include "TextColourChanger.h"

Card::Card(int val, Colour val_colour)
	: m_colour(val_colour)
	, m_value(val)
{
}

void Card::Show_debug() const
{
	TextColourChanger textColour(m_selected);
	std::cout << " [ " << m_value << "." << ColourToString(m_colour) << " ]";
}

void Card::Show_user() const
{
	TextColourChanger textColour(m_selected);
	std::cout << " [ " << ValueToString(m_value) << "." << ColourToSign(m_colour) << " ]";
}

int Card::GetValue() const
{
	return m_value;
}

Card::Colour Card::GetColour() const
{
	return m_colour;
}

void Card::SetSelect(bool option)
{
	m_selected = option;
}

bool Card::IsSelected() const
{
	return m_selected;
}

std::string Card::ColourToString(const Colour& val_colour)
{
	switch (val_colour)
	{
	case Colour::clubs:
		return "clubs";
	case Colour::diamonds:
		return "diamonds";
	case  Colour::hearts:
		return "hearts";
	case Colour::spades:
		return "spades";
	default:
		return "error colour";
	}
}

char Card::ColourToSign(const Colour& val_colour)
{
	switch (val_colour) 
	{
	case Colour::clubs:
		return 5;
	case Colour::diamonds:
		return 4;
	case  Colour::hearts:
		return 3;
	case Colour::spades:
		return 6;
	}
}

std::string Card::ValueToString(const int& val)
{
	switch (val)
	{
	case 1:
		return "A";
	case 11:
		return "J";
	case 12:
		return "Q";
	case 13:
		return "K";
	default:
		return std::to_string(val);
	}
}

