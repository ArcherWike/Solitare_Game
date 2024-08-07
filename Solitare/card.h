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
	int GetValue() const;
	Colour GetColour() const;
	void SetSelect(bool option);
	bool IsSelected() const;

	bool m_selected = false;
private:
	int m_value;
	Colour m_colour;
	static std::string ColourToString(const Colour& val_colour);
	static wchar_t ColourToSign(const Colour& val_colour);

	static std::string ValueToString(const int& val);
};