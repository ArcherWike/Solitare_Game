#include "card.h"
#include <iostream>
#include <windows.h>
#include "TextColourChanger.h"

#include<fcntl.h>
#include <io.h>
#include <windows.h>

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
	std::cout << " [ " << ValueToString(m_value);
	if (m_value != 10)
	{
		std::cout << " ";
	}
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << ColourToSign(m_colour);
	_setmode(_fileno(stdout), _O_TEXT);
	std::cout << " ]";
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

wchar_t Card::ColourToSign(const Colour& val_colour)
{
	switch (val_colour)
	{
	case Colour::clubs:
		return L'\u2663';
	case Colour::diamonds:
		return L'\u2666';
	case  Colour::hearts:
		return L'\u2665';
	case Colour::spades:
		return L'\u2660';
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

